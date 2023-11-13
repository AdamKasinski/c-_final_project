#ifndef ANALYSE_H
#define ANALYSE_H

#include<string>
#include<vector>
#include <unordered_map>
#include "board.h"

using namespace std;

class Analyse{
    
    private:
        Board& board;
        std::unordered_map<int,float> probabilityDistribution;

    public:
        virtual ~Analyse() = default;
        Analyse(Board& board);
        void makeAnalyse();
        Board getBoard();
        void createDistribution();
        unordered_map<int,float> getProbabilityDistribution();
        int goToSquare(int from, int howMany, int numOfFields);
};

#endif