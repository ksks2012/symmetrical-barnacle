#include "../include.h"

class Solution {
public:
    int m = 0;
    int n = 0;
    vector<int> way = {1, 0, -1, 0, 1};
    void DFS(vector<vector<int>> &grid, int x, int y) {
        if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == 0) {
            return;
        }
        grid[x][y] = 0;
        for(int i = 0; i < 4; i++) {
            DFS(grid, x + way[i], y + way[i + 1]);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || j == 0 || n - 1 == i || m - 1 == j) && grid[i][j] == 1) {
                    DFS(grid, i, j);
                }
            }
        }
        
        int s = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                s += grid[i][j];
            }
        }
        return s;
    }
};