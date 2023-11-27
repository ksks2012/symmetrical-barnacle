#include "include.h"

class Solution {
public:
    char posib[3] = {'a', 'b', 'c'};
    void backtracking(vector<string>& tmp, int n, int k, int cur_idx, string cur) {
        if(cur_idx == n) {
            tmp.push_back(cur);
            return;
        }
        if(tmp.size() == k) {
            return;
        }
        
        for(int i = 0; i < 3; i++) {
            if(cur[cur_idx - 1] != posib[i]) {
                backtracking(tmp, n, k, cur_idx + 1, cur + posib[i]);
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> tmp;
        for(int i = 0; i < 3; i++) {
            backtracking(tmp, n, k, 1, string(1, posib[i]));
        }

        if(k > tmp.size()) {
            return "";
        }
        return tmp[k];        
    }
};