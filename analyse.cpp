#include<string>
#include<vector>
#include "analyse.h"
#include "cardType.h"


Analyse::Analyse(Board& board) : board(board){};

int Analyse::goToSquare(int from, int howMany, int numOfFields){
    return (from+howMany)%numOfFields;
};

void Analyse::createDistribution(){
    for (int i = 1; i < 7; i++){
        for (int j = 1; j < 7; j++){
            if (probabilityDistribution.count(i+j) == 0){
                probabilityDistribution[i+j] = 1;
            }else{
                probabilityDistribution[i+j] += 1;
            }
        }
    }
    for (auto& p : probabilityDistribution) p.second /= 36;
};

void Analyse::makeAnalyse(){

    for (int i=0; i < board.getFields().size(); i++){
        for (int j = 2; j < 13; j++){
            int finalPosition = goToSquare(i,j,board.getFields().size());
            switch(board.getFields()[finalPosition]->getType()){

                case(SquareType::jail):
                    board.updateTransitionMatrix(i,finalPosition,probabilityDistribution[j]);
                    board.updateTransitionMatrix(i,board.getJailSquare(),probabilityDistribution[j]);
                    break;
                    
                case(SquareType::city):
                    board.updateTransitionMatrix(i,finalPosition,probabilityDistribution[j]);
                    break;

                case(SquareType::drawCard):

                    SquareCard* squareCard = dynamic_cast<SquareCard*>(board.getFields()[finalPosition]);
                    CardType typ = squareCard->setDrawnCard();

                    if (typ == CardType::goToJail){
                        board.updateTransitionMatrix(i,board.getJailSquare(),probabilityDistribution[j]);
                    }
                    board.updateTransitionMatrix(i,finalPosition,probabilityDistribution[j]);
                    break;
            }
        }
    }
};

Board Analyse::getBoard(){
    return board;
};

unordered_map<int,float> Analyse::getProbabilityDistribution(){
    return probabilityDistribution;
};