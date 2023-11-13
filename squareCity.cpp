#include<string>
#include "squareCity.h"


SquareCity::SquareCity(const SquareType type, const int number, const int rent, const int price) 
: Square(type, number), rent(rent), price(price) {};



int SquareCity::getRent(){
    return rent;
};
int SquareCity::getPrice(){
    return price;
};


int SquareCity::getExpectedValue() {
    return expectedValue;
};

void SquareCity::updateExpectedValue(float value) {
    expectedValue += value;
};

