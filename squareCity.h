#ifndef SQUARECITY_H
#define SQUARECITY_H

using namespace std;
#include<string>
#include "square.h"

class SquareCity : public Square{

    private:
        SquareType type;
        int number;
        int rent;
        int price;
        int expectedValue{ 0 };


    public:
        virtual ~SquareCity() = default;
        SquareCity(const SquareType type, const int number, const int rent, const int price);
        SquareType getType();
        int getRent();
        int getPrice();
        void updateExpectedValue(float value);
        int getExpectedValue();

};

#endif