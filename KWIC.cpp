//
//  KWIC.cpp
//  KWICProj
//
//  Created by Andres Galaviz Gomez on 9/2/16.
//  Copyright © 2016 Andres Galaviz Gomez. All rights reserved.
//

#include "KWIC.hpp"
#include <algorithm>
#include <iostream>
#include <fstream>

KWIC::KWIC()
{
    
}

KWIC::KWIC(std::string inputStream, std::string sortMethod, std::string shiftMethod)
{

    this->inputStream = inputStream;
    this->sortMethod = sortMethod;
    this->shiftMethod = shiftMethod;
}

void KWIC::AddLine(std::string inputLine)
{
    int currentLocation = 0, pastLocation = 0;
    std::vector<std::string> lineIndex;
    while(currentLocation <= inputLine.length())
    {
        if(inputLine[currentLocation] == ' ' || currentLocation == inputLine.length())
        {
            lineIndex.push_back(inputLine.substr(pastLocation, currentLocation-pastLocation));
            pastLocation = currentLocation + 1;
        }
        currentLocation++;
    }
    
    Index.push_back(lineIndex);
}

std::string KWIC::CalculateIndex()
{
    std::string output;
    for(int i = 0; i < this->Index.size(); ++i)
    {
        
        do
        {
            int j;
            for(j = 0; j < this->Index[i].size() - 1; ++j)
            {
                output+= Index[i][j];
                output+= " ";
            }
            output+= Index[i][j];
            output+= "\n";
        } while(std::next_permutation(Index[i].begin(), Index[i].end()));
        // Lo probe con permutation pero hay que cambiarlo
    }
    
    return output;
}

void KWIC::ReadStream()
{
    std::ifstream input;
    std::string currentLine;
    if(this->inputStream == "cin")
    {
        
        while(getline(std::cin, currentLine))
        {
            AddLine(currentLine);
        }
    }
    else
    {
        std::ifstream inputFile(this->inputStream);
        
        while(getline(inputFile, currentLine))
        {
            AddLine(currentLine);
        }
    }

}