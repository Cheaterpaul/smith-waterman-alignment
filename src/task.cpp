#include "task.h"
#include <vector>
#include "smithwaterman.h"

extern int fileSize1;
extern int fileSize2;

extern std::vector<std::vector<Result>> results;

Task::Task(size_t start, size_t end): seq_start(start), seq_end(end) {
}

void Task::operator()() {
    for (size_t i = seq_start; i < seq_end && i < fileSize1-1;++i) {
        int maxValue = 0;
        size_t seq2_start;
        for (size_t j = 0; j < fileSize2-49;++j) {
            int value = compare(i,j);
            if (value > maxValue) {
                maxValue = value;
                seq2_start = j;
            }
        }
        if(maxValue > 69) {
            maxValues.push_back(Result(i,seq2_start, maxValue));
        }
    }
    
    results.push_back(maxValues);
}


