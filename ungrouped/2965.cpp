#include "include.h"

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.size();

        vector<int> tmp(m * n, 0);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                tmp[grid[i][j] - 1]++;
            }
        }    

        vector<int> ans(2, 0);

        for(int i = 0; i < tmp.size(); i++) {
            if(tmp[i] == 0)
                ans[1] = i + 1;
            if(tmp[i] == 2)
                ans[0] = i + 1;
        }

        return ans;
    }
};