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
    
    std::vector<int> row1(51, 0);
    std::vector<int> row2(51);
    for (size_t i = 1; i <= 50;++i) {
        for (size_t j = 1; j <= 50;++j) {
            int value = std::max(std::max(0,row1[j-1] + (file1[x+i] == file2[y+j]?2:-1)), std::max(row1[j] -1, row2[j-1]-1));
            row2[j] = value;
            if (maxValue < value) {
                maxValue = value;
            }
        }
        row1.swap(row2);

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
