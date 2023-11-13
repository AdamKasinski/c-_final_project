#ifndef SQUARECARD_H
#define SQUARECARD_H

using namespace std;
#include<string>
#include "square.h"
#include "cardType.h"


class SquareCard : public Square{
    public:
        using Square::Square;
        virtual ~SquareCard() = default;
        int getNumber();
        SquareType getType();
        CardType setDrawnCard();

    private:
        SquareType type;
        int number;
};

#endif