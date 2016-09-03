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
    std::string outputStream = "cout";
    std::string inputStream = "cin";
    
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
                        inputStream = std::string(argv[i]);
                        break;
                    case 'o':
                        ++i;
                        outputStream = std::string(argv[i]);
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
    
    
    indexSystem = new KWIC(inputStream, sortMethod, shiftMethod);
    indexSystem->ReadStream();

    std::vector<std::string> calculatedOutput = indexSystem->CalculateIndex();
    Printer printer;
    printer.print(calculatedOutput, "cout");


    
}