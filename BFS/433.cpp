#include "include.h"

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> queue;
        unordered_set<string> visited;
        queue.push(start);
        visited.insert(start);
        
        int steps = 0;
        while (!queue.empty()) {
            int q_size = queue.size();
            
            for (int j = 0; j < q_size; j++) {
                string top = queue.front();
                queue.pop();

                if (top == end) {
                    return steps;
                }
                
                for (char c: "ACGT") {
                    for (int i = 0; i < top.size(); i++) {
                        string tmp = top;
                        tmp[i] = c;
                        if (!visited.count(tmp) && find(bank.begin(), bank.end(), tmp) != bank.end()) {
                            queue.push(tmp);
                            visited.insert(tmp);
                        }
                    }
                }
            }  
            steps++;
        }
        return -1;
    }
};