#include "include.h"

class Solution {
public:
    int m, n;
    vector<int> way = {1, 0, -1, 0, 1};
    int DFS(vector<vector<char>>& grid, int x, int y) {
        if(x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == '0')
            return 1;
        
        grid[x][y] = '0';
        int res = 1;

        for(int i = 0; i < 4; i++) {
            int tmp_x = x + way[i];
            int tmp_y = y + way[i + 1];
            res &= DFS(grid, tmp_x, tmp_y);
        }
        return res;
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    ans += DFS(grid, i, j);
                }
            }
        }

        return ans;
    }
};