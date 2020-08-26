#include <iostream>
#include <fstream>
#include "iostuff.h"
#include "result.h"
#include <algorithm>

extern std::string fileName1;
extern std::string fileName2;
extern int threadsAmount;
extern std::string outFileName;

extern std::string file1;
extern std::string file2;
extern int fileSize1;
extern int fileSize2;

extern std::vector<std::vector<Result>> results;

size_t getFileSize(std::fstream &file) {
    std::streampos size = file.tellg();
    file.seekg(0, std::ios::end);
    size = file.tellg() - size;
    file.seekg(0);
    return size;
}

void readFile() {
    std::fstream in1(fileName1);
    std::fstream in2(fileName2);
    fileSize1 = getFileSize(in1);
    fileSize2 = getFileSize(in2);
    file1 = std::string(fileSize1, ' ');
    file2 = std::string(fileSize2, ' ');
    
    in1.read(const_cast<char*>(file1.data()), fileSize1);
    in2.read(const_cast<char*>(file2.data()), fileSize2);
}

void removeHeader() {
    for(size_t i = 0 ; i < fileSize1; ++i) {
        if(file1[i] == '\n') {
            file1.erase(0, i);
            break;
        }
    }
    for(size_t i = 0 ; i < fileSize2; ++i) {
        if(file2[i] == '\n') {
            file2.erase(0, i);
            break;
        }
    }
    file1.erase(remove(file1.begin(), file1.end(), '\n'), file1.end());
    std::transform(file1.begin(), file1.end(), file1.begin(), toupper);
    file2.erase(remove(file2.begin(), file2.end(), '\n'), file2.end());
    //boost::erase_all(file2, "\n");
    std::transform(file1.begin(), file1.end(), file1.begin(), toupper);
    
    fileSize1 = file1.size();
    fileSize2 = file2.size();
}

void writeResult() {
    std::ofstream output(outFileName);
    output << fileName1 << "," << fileName2 << "," << "value\n";
    for(std::vector<Result> vec : results) {
        for (Result result : vec){
            output << result.start1 << "," << result.start2 << "," << result.value << "\n";
        }
    }
}

void processInputFiles() {
    readFile();
    removeHeader();
}

void processOutputFiles() {
    writeResult();
}

