#include "include.h"

// TL
class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        long long res = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    // Count horizontal and vertical lines
                    int horizontal = 0, vertical = 0;
                    for (int k = 0; k < m; ++k) {
                        if (grid[i][k] == 1) horizontal++;
                    }
                    for (int k = 0; k < n; ++k) {
                        if (grid[k][j] == 1) vertical++;
                    }
                    // Subtract the point itself
                    horizontal--;
                    vertical--;
                    // Calculate right triangles
                    res += horizontal * vertical;
                }
            }
        }

        return res;        
    }
};


class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> row_counts(n, 0);
        vector<int> col_counts(m, 0);
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (grid[r][c] == 1) {
                    row_counts[r]++;
                    col_counts[c]++;
                }
            }
        }
        long long res = 0;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (grid[r][c] == 1) {
                    res += (row_counts[r] - 1) * (col_counts[c] - 1);
                }
            }
        }
        return res;
    }
};