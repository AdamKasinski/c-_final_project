#include <random>
#include <string>
#include "card.h"
using namespace std;

    
Card::Card(): type(drawCard()){}

CardType Card::drawCard(){
    
    srand(time(NULL));
    int number = rand() % 10 + 1;
    
    if (number < 5)
    {
        return CardType::pay;
    }
    else if (number < 9)
    {
        return CardType::receive;
    }
    else
    {
        return CardType::goToJail;
    };
};

CardType Card::getCard(){
    return type;
};