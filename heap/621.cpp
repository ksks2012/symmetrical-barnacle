#include "../include.h"

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> m;
        for(int i = 0; i < tasks.size(); i++) {
            m[tasks[i]]++;
        }

        priority_queue<pair<int, char>> tasks_queue;
        for(auto i : m) {
            tasks_queue.push({i.second, i.first});
        }

        int res = 0;
        while(!tasks_queue.empty()) {
            int time = 0;
            vector<pair<int, char>> tmp;
            for(int i = 0; i < n + 1; i++) {
                if(!tasks_queue.empty()) {
                    tmp.push_back(tasks_queue.top());
                    tasks_queue.pop();
                    time++;
                }
            }
            for(auto t: tmp) {
                if(--t.first) {
                    tasks_queue.push(t);
                }
            }
            res += !tasks_queue.empty() ? n + 1 : time;
        }

        return res;
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        int count = 0;
        for(auto t : tasks)
        {
            mp[t]++;
            count = max(count, mp[t]);
        }
        
        int res = (count - 1) * (n + 1);
        for(auto i : mp) {
            if(i.second == count) 
                res++;
        }
            
        return max((int)tasks.size(), res);
    }
};