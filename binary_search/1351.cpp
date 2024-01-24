#include "../include.h"

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] < 0) 
                    ans++;
            }
        }

        return ans;
    }
};


class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();

        int i = m - 1;
        int j = 0;

        while(i >= 0 && i < m && j >= 0 && j < n) {
            if(grid[i][j] < 0) {
                ans += n - j;
                i = i - 1;
            } else {
                j = j + 1;
            }
        }

        return ans;
    }
};