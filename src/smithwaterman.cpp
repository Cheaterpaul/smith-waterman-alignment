#include <string>
#include <vector>
#include <iostream>
#include "smithwaterman.h"
#include <string_view>
#include "result.h"
#include "task.h"
#include <thread>
#include <algorithm>

extern int threadsAmount;

extern std::string file1;
extern std::string file2;
extern int fileSize1;
extern int fileSize2;

extern std::vector<std::vector<Result>> results;

int compare(int x,int y) {
    
    int maxValue = 0;
    
    std::vector<int> collum1(51, 0);
    std::vector<int> collum2(51,0);
    for (size_t i = 1; i <= 50;++i) {
        int a = 0;
        for (size_t j = 1; j <= 50;++j) {
            int value = std::max(collum1[j]-1,a-1);
            int b = collum1[j-1]+2;
            if (!(value > b )) {
                if (file1[x+i] != file2[y+j]) {
                    b -=3;
                }
                if (b > value) {
                    value = b;
                }
            }
            if (value > 0) {
                a = collum2[j] = value;
                if (maxValue < value) {
                    maxValue = value;
                }
            } else {
                a = 0;
            }
            
        }
        collum1.swap(collum2);

    }
    return maxValue;
}

void compare() {
    
    size_t frames = fileSize1 / threadsAmount;
    
    std::vector<Task> tasks;
    
    for (size_t i = 0; i < threadsAmount;++i){
        tasks.push_back(Task(i * frames, i == threadsAmount-1?fileSize1-1:(i+1)*frames));
    }
    
    std::vector<std::thread> threads;

    for (Task task: tasks) {
        threads.push_back(std::thread(task));
    }
    
    std::for_each(threads.begin(),threads.end(), std::mem_fn(&std::thread::join));
}
