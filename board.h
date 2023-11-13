#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>
#include <memory>
#include "square.h"
#include "squareCard.h"
#include "squareCity.h"
#include "squareJail.h"

class Board {
    
    private:
        std::vector<Square*> fields;
        std::vector<std::vector<float>> transitionMatrix;
        int jailSquare; /*number of the field is used quite often, so I decided to keep it in separte variable*/

    public:
        virtual ~Board() = default;
        Board();
        void setFields(Square* square);
        void createTransitionMatrix();
        void updateTransitionMatrix(int squareFrom, int squareTo, float value);
        std::vector<Square*> getFields();
        std::vector<std::vector<float>> getTransitionMatrix();
        int getJailSquare();
        void setJailSquare(int number);                                                                                                                                     
};

#endif