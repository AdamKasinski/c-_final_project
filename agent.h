#ifndef AGENT_H
#define AGENT_H

#include<string>
#include<vector>
#include "square.h"
#include "squareCity.h"


class Agent {
	
	private:
		int wealth;
		int field;
		std::vector<SquareCity*> ownedFields;
		int isInJail{0};

	public:
		virtual ~Agent() = default;
		Agent();
		int getField();
		std::vector<SquareCity*> getOwnedFields();
		void updateOwnedFields(SquareCity* city);
		void move(int MoveTo);
		void updateIsInJail();
		bool checkIfOwn(SquareCity* city);
		bool checkIfInJail();

};

#endif