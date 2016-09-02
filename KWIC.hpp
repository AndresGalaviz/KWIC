//
//  KWIC.hpp
//  KWICProj
//
//  Created by Andres Galaviz Gomez on 9/2/16.
//  Copyright © 2016 Andres Galaviz Gomez. All rights reserved.
//

#ifndef KWIC_hpp
#define KWIC_hpp
#include <stdio.h>
#include <string>
#include <vector>
#endif /* KWIC_hpp */

class KWIC
{
public:
    KWIC();
    
    // sortMethod = 'asc' | 'desc'
    KWIC(std::string inputStream, std::string sortMethod, std::string shiftMethod);
    
    // Llega una linea, se tokeniza y se generan todas las permutaciones, cada permutacion
    // se agrega a Index y se sortea de nuevo de acuerdo sortMethod
    void AddLine(std::string line);
    std::string CalculateIndex();
    
private:
    std::string sortMethod;
    std::string shiftMethod;
    std::vector<std::vector<std::string> > Index;
};