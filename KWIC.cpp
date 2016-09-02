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

KWIC::KWIC()
{
    
}

KWIC::KWIC(std::string inputStream, std::string sortMethod, std::string shiftMethod)
{
    if(inputStream == "cin")
    {
        std::string currentLine;
        while(getline(std::cin, currentLine))
        {
            AddLine(currentLine);
        }
    }
    else
    {
        
        
    }
    
    CalculateIndex();
}

void KWIC::AddLine(std::string inputLine)
{
    int currentLocation = 1, pastLocation = 1;
    std::vector<std::string> lineIndex;
    while(inputLine[currentLocation] != '\n')
    {
        if(inputLine[currentLocation] == ' ' || inputLine[currentLocation] == '\"')
        {
            std::cout <<inputLine.substr(pastLocation, currentLocation-currentLocation-1) << " ";
            lineIndex.push_back(inputLine.substr(pastLocation, currentLocation-currentLocation-1));
            pastLocation = currentLocation;
        }
        currentLocation++;
    }
    std::cout << "\n";
}

std::string KWIC::CalculateIndex()
{
    return " ";
}