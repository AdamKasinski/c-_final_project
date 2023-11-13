#include<string>
#include<vector>
#include "agent.h"


Agent::Agent() : field(1), wealth(1000) {};


int Agent::getField() {
	return field;
};

std::vector<SquareCity*> Agent::getOwnedFields() {
	return ownedFields;
};

void Agent::updateOwnedFields(SquareCity* city) {
	ownedFields.push_back(city);
};

void Agent::move(int moveTo) {
	field = moveTo;
};


void Agent::updateIsInJail() {
	if (isInJail == 2) {
		isInJail = 0;
	}
	isInJail++;
};

bool Agent::checkIfOwn(SquareCity* city) {
	for (auto& cit : ownedFields) {
		if (city->getNumber() == cit->getNumber()) {
			return true;
		}
	}
	return false;
};

bool Agent::checkIfInJail() {
	return isInJail == 0;
}