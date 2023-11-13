#ifndef EXPECTEDVALUE_H
#define EXPECTEDVALUE_H


#include<string>
#include<vector>
#include<unordered_map>
#include "board.h"


class ExpectedValue {

	private:
		
		int numberOfRounds;
		std::unordered_map<int, float> expectedValues;
		Board& board;
		float probabilityOfSequence(float prob);
		float newtonSymbol(int n, int k);
		float factorial(int number);

	public:

		ExpectedValue(int numberOfRounds, Board& board);
		int getNumberOfRounds();
		void updateExpectedValues();
		std::unordered_map<int, float> getExpectedValues();

};

#endif