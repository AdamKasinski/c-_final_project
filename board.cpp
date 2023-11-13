using namespace std;
#include <string>
#include <vector>
#include <memory>
#include "board.h"


Board::Board(){};

void Board::setFields(Square* square){

    fields.push_back(square);

};

void Board::setJailSquare(int number){
    jailSquare = number;
}

void Board::createTransitionMatrix(){
    transitionMatrix = std::vector<std::vector<float>>(fields.size(), std::vector<float>(fields.size(), 0));
};

void Board::updateTransitionMatrix(int squareFrom, int squareTo, float value){
    transitionMatrix[squareFrom][squareTo] += value;
};

std::vector<Square*> Board::getFields(){
    return fields;
};
std::vector<std::vector<float>> Board::getTransitionMatrix(){
    return transitionMatrix;
};
int Board::getJailSquare(){
    return jailSquare;
}