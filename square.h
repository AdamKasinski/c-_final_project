#ifndef SQUARE_H
#define SQUARE_H

using namespace std;
#include<string>
#include "squareType.h"

class Square{
    public:
        virtual ~Square() = default;
        Square(const SquareType type, const int number);
        int getNumber();
        SquareType getType();

    private:
        SquareType type;
        int number;
};

#endif