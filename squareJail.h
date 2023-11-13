#ifndef SQUAREJAIL_H
#define SQUAREJAIL_H

using namespace std;
#include<string>
#include "square.h"


class SquareJail : public  Square{
    public:
        using Square::Square;
        virtual ~SquareJail() = default;
        int getNumber();
        std::string getType();

    private:
        std::string type;
        int number;
        std::string drawnCard;
};

#endif