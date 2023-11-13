#ifndef GAME_H
#define GAME_H

#include<string>
#include<vector>
#include "agent.h"
#include "board.h"
#include <unordered_map>

using namespace std;

class Game {
	
	private:

		Agent agent1;
		Agent agent2;
		std::unordered_map<int, int> expectedValues;
		Board& board;

	public:
		
		Game(Board& board);
		void setExpectedValues();
		void play(int maxRound);
		std::unordered_map<int, int> getExpectedValues();
		void playTurn(Agent& currAgent);

};

#endif