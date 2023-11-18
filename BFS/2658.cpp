#include "../include.h"

class Solution {
public:
    vector<int> way = {1, 0, -1, 0, 1};
    int ans;
    int m;
    int n;
    int DFS(vector<vector<int>>& grid, int x, int y) {
        if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) {
            return 0;
        }
        int tmp = grid[x][y];
        grid[x][y] = 0;

        for(int i = 0; i < 4; i++) {
            int tmp_x = x + way[i];
            int tmp_y = y + way[i + 1];
            tmp += DFS(grid, tmp_x, tmp_y);
        }
        return tmp;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        ans = 0;
        m = grid.size();
        n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans = max(ans, DFS(grid, i, j));
            }
        }
        return ans;    
    }
};