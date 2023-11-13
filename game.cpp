#include "game.h"
#include <random>
#include "squareType.h"

Game::Game(Board& board) : board(board), agent1(Agent()), agent2(Agent()) {};

void Game::setExpectedValues() {
	for (auto& field : board.getFields()) {
		if (field->getType() == SquareType::city) {
			SquareCity* squareField = dynamic_cast<SquareCity*>(field);
			if (expectedValues.count(field->getNumber()) == 0) {
				expectedValues[field->getNumber()] = squareField->getExpectedValue();
			}
		}
	}
};


void Game::playTurn(Agent& currAgent) {
	
	std::vector<float> probabilities = board.getTransitionMatrix()[currAgent.getField()];
	std::random_device rd;
	std::mt19937 gen(rd());
	std::discrete_distribution<> dist(probabilities.begin(), probabilities.end());
	
	int drawnField = dist(gen);
	currAgent.move(drawnField);
	
	if (board.getFields()[currAgent.getField()]->getType() == SquareType::jail) {
		currAgent.move(board.getJailSquare());
		currAgent.updateIsInJail();
	}
	else if (board.getFields()[currAgent.getField()]->getType() == SquareType::drawCard) {
		SquareCard* squareCard = dynamic_cast<SquareCard*>(board.getFields()[drawnField]);
		CardType typ = squareCard->setDrawnCard();

		if (typ == CardType::goToJail) {
			currAgent.move(board.getJailSquare());
			currAgent.updateIsInJail();
		}
	}
	else if (board.getFields()[currAgent.getField()]->getType() == SquareType::city) { 
		SquareCity* squareCity = dynamic_cast<SquareCity*>(board.getFields()[drawnField]);
		
		bool isOwner = currAgent.checkIfOwn(squareCity);

		if (isOwner && squareCity->getNumberOfHouses() < 5) {
			squareCity->setNumberOfHouses();
			squareCity->updateExpectedValue(-100);
		}
		else if (!isOwner) {
			if (!squareCity->checkIfIsOwned()) {

				currAgent.updateOwnedFields(squareCity);
				squareCity->bought();

			}
			else if (squareCity->checkIfIsOwned()) {
				squareCity->updateExpectedValue(squareCity->getRent());
			}
		}
	}
};


void Game::play(int maxRound) {
	
	int currentRound = 0;

	while (currentRound < maxRound) {
		if (currentRound % 2 == 0) {
			if (!agent1.checkIfInJail()) {
				playTurn(agent1);
			}
			else {
				agent1.updateIsInJail();
			}
		}
		else {
			if (!agent2.checkIfInJail()) {
				playTurn(agent2);
			}
			else {
				agent2.updateIsInJail();
			}
		}
		currentRound++;
	}
	setExpectedValues();
};

std::unordered_map<int, int> Game::getExpectedValues() {
	return expectedValues;

};
