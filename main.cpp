#include <iostream>
#include <fstream>
#include <vector>
#include "KWIC.hpp"
#include "Printer.hpp"

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    KWIC *indexSystem;
    
    std::string sortMethod = "asc";
    std::string shiftMethod = "circular";
    std::string output = "cout";
    std::string input = "cin";
    
    if(argc > 1)
    {
        
        for(int i = 1; i < argc; ++i)
        {
            int flagSelector = 0;
            if(argv[i][flagSelector] == '-')
            {
                flagSelector++;
                
                switch(argv[i][flagSelector])
                {
                    case 'i':
                        ++i;
                        input = std::string(argv[i]);
                        break;
                    case 'o':
                        ++i;
                        output = std::string(argv[i]);
                        break;
                    case 's':
                        ++i;
                        sortMethod = std::string(argv[i]);
                        break;
                    case 't':
                        ++i;
                        shiftMethod = std::string(argv[i]);
                        break;
                    default:
                        std::cout << "Error de uso" << "\n";
                        break;
                }
            }
            else
            {
                std::cout << "Error de uso" << "\n";
            }
            
        }
    }
    
    indexSystem = new KWIC();
    // indexSystem = new KWIC(std::string(argv[1]), sortMethod, shiftMethod);
    // indexSystem = new KWIC(input, sortMethod, shiftMethod);
    
    // Printer printer = new Printer();
    // std::string output = indexSystem.CalculateIndex();
    // printer.print(output,)
    // std::string currentLine;
    // KWIC *indexSystem = new KWIC();
    
    // indexSystem->CalculateIndexOutput();
    // indexSystem->PrintIndexOutput();
    
}