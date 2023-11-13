#include<string>
#include "square.h"
#include "squareType.h"

Square::Square(const SquareType type, const int number) : type(type), number(number) {}

int Square::getNumber(){
    return number;
};

SquareType Square::getType(){
    return type;
};

