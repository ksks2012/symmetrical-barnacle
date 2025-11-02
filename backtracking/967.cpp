#include "include.h"

class Solution {
public:
    void backtracking(vector<int>& res, int n, int k, int cur_idx, string cur) {
        if(cur_idx == n) {
            res.push_back(stoi(cur));
            return;
        }
        
        int up = cur[cur_idx - 1] - '0' + k;
        if(up < 10) {
            backtracking(res, n, k, cur_idx + 1, cur + to_string(up));
        }
        if(k != 0) {
            int down = cur[cur_idx - 1] - '0' - k;
            if (down >= 0) {
                backtracking(res, n, k, cur_idx + 1, cur + to_string(down));
            }
        }
    }

    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        for(int i = 1; i <= 9; i++)
            backtracking(res, n, k, 1, to_string(i));
        return res;
    }
};