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


void Printer::print (std::string buffer, std::string filedsc){
    std::ofstream file;
    
    if(filedsc.compare("stdout") == 0){
        std::cout << buffer;
    }else{
        file.open(filedsc);
        file << buffer;
        file.close();
    }
}