#include<iostream>
#include "read.h"
#include "analyse.h"
#include "board.h"
#include "agent.h"
#include "game.h"
#include "expectedValue.h"

using namespace std;

int main() {
    Board board = Board();
    Read::orm("D:\\ProjC++\\firstProject\\inputTable.csv", board);
    Analyse analyse = Analyse(board);
    analyse.createDistribution();
    analyse.makeAnalyse();
    std::vector<std::vector<float>> matrix = board.getTransitionMatrix();
    for (auto& row : matrix) {
        for (auto& cell : row) {
            cout << cell << " ";
        }
    }
    return 0;
};
