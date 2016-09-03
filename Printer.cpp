//
//  Printer.cpp
//  KWICProj
//
//  Created by Andres Galaviz Gomez on 9/2/16.
//  Copyright © 2016 Andres Galaviz Gomez. All rights reserved.
//

#include "Printer.hpp"
#include <iostream>
#include <fstream>
#include <string>


void Printer::print(std::vector<std::string> output, std::string outputLocation)
{
    std::ofstream file;
    if(outputLocation != "cout")
    {
        file.open(outputLocation);
    }
    
    for(int i = 0; i < output.size(); ++i)
    {
        
        if(outputLocation == "cout")
        {
            std::cout << output[i];
        }
        else
        {
            
            file << output[i];
        }
    }

    
    if(file.is_open())
    {
        file.close();
    }
    
}