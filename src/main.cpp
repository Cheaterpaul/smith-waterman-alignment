#include <iostream>
#include <string>
#include "iostuff.h"
#include "smithwaterman.h"

extern std::string fileName1;
extern std::string fileName2;
extern int threadsAmount;
extern std::string outFileName;

int main(int argc, char **argv) {
    if (argc != 5) {
        std::cout << "wrong argument count\n";
    }
    
    fileName1 = argv[1];
    fileName2 = argv[2];
    threadsAmount = std::stoi(argv[3]);
    outFileName = argv[4];
    
    processInputFiles();
    
    compare();
    
    processOutputFiles();
    
    return 0;
}
