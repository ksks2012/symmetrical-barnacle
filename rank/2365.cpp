#include "include.h"

class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long res = 0;
        unordered_map<int, int> last_task;
        for(int i = 0; i < tasks.size(); i++) {
            if(last_task.find(tasks[i]) != last_task.end()) {
                int diff = res - last_task[tasks[i]] - 1;
                res += space > diff ? space - diff: 1;
            } else {
                res += 1;
            }
            last_task[tasks[i]] = res;
        }

        return res;
    }
};

class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long res = 0;
        unordered_map<int, long long> last_task;
        for(int i = 0; i < tasks.size(); i++) {
            if(last_task.count(tasks[i])) {
                last_task[tasks[i]] = res = max(res, last_task[tasks[i]] + space) + 1;
            } else {
                last_task[tasks[i]] = ++res;
            }
        }

        return res;
    }
};