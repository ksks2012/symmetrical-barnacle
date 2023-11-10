#include "../include.h"

class Solution {
public:
    int m = 0;
    int n = 0;
    vector<int> way = {1, 0, -1, 0, 1};

    int DFS(vector<vector<int>>& grid, int x, int y) {
        if(x < 0 || y < 0 || x >= m || y >= n)
            return 0;
        if(grid[x][y] == 1)
            return 1;

        grid[x][y] = 1;

        int res = 1;
        for(int i = 0; i < 4; i++) {
            int tmp_x = x + way[i];
            int tmp_y = y + way[i + 1];
            res &= DFS(grid, tmp_x, tmp_y);
        }
        return res;
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    count += DFS(grid, i, j);
                }
            }
        }
        
        return count;
    }
};