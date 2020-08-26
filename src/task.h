#pragma once

#include <vector>
#include "result.h"

class Task {
    
private:
    size_t seq_start;
    size_t seq_end;
    std::vector<Result> maxValues;
    
public:
    Task(size_t start, size_t end);
    
    void operator() ();
    
};
