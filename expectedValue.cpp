#include "expectedValue.h"
#include<cmath>
#include <numeric>

ExpectedValue::ExpectedValue(int numberOfRounds, Board& board) : 
	numberOfRounds(numberOfRounds), board(board) {};



int ExpectedValue::getNumberOfRounds() {
	return numberOfRounds;
}

float ExpectedValue::factorial(int number) {
    float result = 1;
    for (int i = 1; i <= number; i++) {
        result *= i;
    }
    return result;
}

float ExpectedValue::newtonSymbol(int n, int k) {
    return factorial(n) / factorial(k) * factorial(n - k);
}

float ExpectedValue::probabilityOfSequence(float prob) {
    float result = 1;
    for (int i = 1;i <= numberOfRounds;i++) {
        float coeff = newtonSymbol(numberOfRounds, i);
        result += coeff * pow(prob, i) * pow(1 - prob, numberOfRounds - i);
    }
    return result;
}


void ExpectedValue::updateExpectedValues() {
    
    std::vector<float> cumm_prob(board.getTransitionMatrix().size(),0);

    for (int i = 0; i < board.getTransitionMatrix().size(); ++i) {
        /*cumm_prob[i] = std::accumulate(board.getTransitionMatrix()[i].begin(), board.getTransitionMatrix()[i].end(), 0.0f);*/
        for (int j = 0; j < board.getTransitionMatrix()[i].size();++j) {
            cumm_prob[i] += board.getTransitionMatrix()[i][j];
        }
        
    }

    for (auto& field : board.getFields()) {
        if (field->getType() == SquareType::city) {
            SquareCity* squareCity = dynamic_cast<SquareCity*>(field);
            float prob = cumm_prob[squareCity->getNumber()];
            expectedValues[squareCity->getNumber()] = prob * squareCity->getPrice() + probabilityOfSequence(prob);
        }
    }
}

std::unordered_map<int, float> ExpectedValue::getExpectedValues() {
    return expectedValues;
}