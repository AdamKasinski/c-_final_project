#ifndef READ_H
#define READ_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "board.h"
#include "square.h"
#include "squareType.h"
#include "cardType.h"


using namespace std;

class Read{
    
    public:
        static void orm(std::string path, Board& board);
};

#endif