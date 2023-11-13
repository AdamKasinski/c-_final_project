#include<memory>
#include <iostream>
#include "read.h"
#include "squareType.h"
#include "square.h"

void Read::orm(std::string path, Board& board){


    vector<vector<string>> content;
    vector<string> row;
    string line, word;

    fstream file(path, ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            row.clear();

            stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else
        cout << "Could not open the file\n";

    for (auto& row : content)
    {
        SquareType type;

        if (row[1].compare("city") == 0) {

            type = SquareType::city;

        }
        else if (row[1].compare("jail") == 0)
        {
            type = SquareType::jail;

        }
        else if (row[1].compare("drawCard") == 0)
        {
            type = SquareType::drawCard;
        }

        switch (type)
        {
        case SquareType::city:
        {
            int arg1 = stoi(row[0]);
            SquareCity* boardSquare = new SquareCity(type, arg1, stoi(row[3]), stoi(row[2]));
            board.setFields(boardSquare);
            break;
        }
        case SquareType::jail:
        {
            SquareJail* jailSquare = new SquareJail(type, stoi(row[0]));
            board.setFields(jailSquare);
            board.setJailSquare(stoi(row[0]));
            break;
        }
        case SquareType::drawCard:
        {
            SquareCard* cardSquare = new SquareCard(type, stoi(row[0]));
            board.setFields(cardSquare);
            break;
        }
        };
    }
    board.createTransitionMatrix();

};
