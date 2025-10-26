#include "include.h"

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int res = 0;

        // Top view
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    res += 1;
                }
            }
        }

        // Front view
        for (int i = 0; i < n; ++i) {
            int max_row = 0;
            for (int j = 0; j < n; ++j) {
                max_row = max(max_row, grid[i][j]);
            }
            res += max_row;
        }

        // Side view
        for (int j = 0; j < n; ++j) {
            int max_col = 0;
            for (int i = 0; i < n; ++i) {
                max_col = max(max_col, grid[i][j]);
            }
            res += max_col;
        }

        return res;
    }
};    