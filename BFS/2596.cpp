#include "../include.h"

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        // ????
        if(grid[0][0] != 0) {
            return false;
        }
        unordered_map<int, pair<int, int>> tmp;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                tmp[grid[i][j]] = pair<int, int>(i, j);
            }
        }

        for(int i = 0; i < m * n - 1; i++) {
            int tmp_x  = abs(tmp[i].first - tmp[i + 1].first);
            int tmp_y = abs(tmp[i].second - tmp[i + 1].second);

            if(tmp_x * tmp_y != 2)
                return false;
        }

        return true;
    }
};