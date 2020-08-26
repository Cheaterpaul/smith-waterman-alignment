#include <string>
#include <vector>
#include <iostream>
#include "smithwaterman.h"
#include <string_view>
#include "result.h"

extern std::string file1;
extern std::string file2;
extern int fileSize1;
extern int fileSize2;

extern std::vector<std::vector<Result>> results;

int compare(int x,int y) {
    
    int maxValue = 0;
    
    std::vector<int> collum1(51, 0);
    std::vector<int> collum2(51);
    for (size_t i = 1; i <= 50;++i) {
        for (size_t j = 1; j <= 50;++j) {
            int value = collum1[j]-1>collum2[j-1]-1?collum1[j]-1:collum2[j-1]-1;
            if (value <= collum1[j-1]+2) {
                int value2 = collum1[j-1] + (file1[x+i] == file2[y+j] ? 2 : -1);
                if (value2 > value) {
                    value = value2;
                }
            }
            collum2[j] = value;
            if (maxValue < value) {
                maxValue = value;
            }
            
        }
        collum1.swap(collum2);

    }
    return maxValue;
}

void compare() {
    for (int i = 0; i < fileSize1-49; ++i) {
        std::vector<Result> result;
        for (int j = 0; j < fileSize2-49; ++j) {
            int value = compare(i, j);
            if (value > 70) {
                result.push_back(Result(i,j,value));
            }
        }
        results.push_back(result);
    }
}
