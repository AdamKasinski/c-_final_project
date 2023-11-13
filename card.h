#ifndef CARD_H
#define CARD_H

#include<string>
#include "cardType.h"

using namespace std;

class Card{
    
    public:
        Card();
        CardType drawCard();
        CardType getCard();
    
    private:
        CardType type;  
};


#endif