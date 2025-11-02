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

class Solution {
public:
    void dfs(vector<int>& res, int remaining, int k, int cur) {
        if (remaining == 0) {
            res.push_back(cur);
            return;
        }
        int last = cur % 10;
        int up = last + k;
        if (up < 10) 
            dfs(res, remaining - 1, k, cur * 10 + up);
        if (k != 0) {
            int down = last - k;
            if (down >= 0) 
                dfs(res, remaining - 1, k, cur * 10 + down);
        }
    }

    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        if (n == 1) { // include 0 when n == 1
            res.reserve(10);
            for (int i = 0; i <= 9; ++i) 
                res.push_back(i);
            return res;
        }
        res.reserve(9 << min(n - 1, 7)); // heuristic reserve to reduce reallocs
        for (int i = 1; i <= 9; ++i)
            dfs(res, n - 1, k, i);
        return res;
    }
};