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
    this->inputStream = "cin";
    this->sortMethod = "asc";
    this->shiftMethod = "circular";
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

std::vector<std::string> KWIC::CalculateIndex()
{
    std::vector<std::string> output;
    for(int i = 0; i < this->Index.size(); ++i)
    {
        
        for(int j = 0; j < this->Index[i].size(); ++j)
        {
            if(this->shiftMethod == "circular")
            {
            
                int currIndex = j;
                std::string currentLine;
                do
                {
                    std::string data = Index[i][currIndex];
                    std::transform(data.begin(), data.end(), data.begin(), ::tolower);
                    currentLine += data;
                    currIndex++;
                    currIndex = currIndex%this->Index[i].size();
                    if(currIndex != j)
                    {
                        currentLine += " ";
                    }
                    else
                    {
                        currentLine += "\n";
                    }

                    
                } while(currIndex != j);
                output.push_back(currentLine);
            }
        }
    }
    
    if(this->sortMethod == "des")
    {
        sort(output.begin(), output.end(), std::greater<std::string>());
    }
    else
    {
        sort(output.begin(), output.end());
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