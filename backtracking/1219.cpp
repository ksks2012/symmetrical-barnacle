#include "include.h"

// TLE
class Solution {
public:
    int m;
    int n;
    vector<int> way = {1, 0, -1, 0, 1};

    void backtracking(vector<vector<int>> grid, int x, int y, int sum, vector<vector<int>> visited, int &ans) {
        ans = max(ans, sum);
        int origin;
        for(int i = 0; i < 4; i++) {
            int tmp_x = x + way[i];
            int tmp_y = y + way[i + 1]; 
            if(tmp_x >= 0 && tmp_x < m && tmp_y >= 0 && tmp_y < n) {
                if(grid[tmp_x][tmp_y] != 0 && visited[tmp_x][tmp_y] != 1) {
                    visited[tmp_x][tmp_y] = 1;
                    backtracking(grid, tmp_x, tmp_y, sum + grid[tmp_x][tmp_y], visited, ans);
                    visited[tmp_x][tmp_y] = 0;
                }
            }
        }
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] != 0) {
                    visited[i][j] = 1;
                    backtracking(grid, i, j, grid[i][j], visited, ans);
                    visited[i][j] = 0;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> way = {1, 0, -1, 0, 1};
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxGold = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                maxGold = max(maxGold, findMaxGold(grid, m, n, i, j));
            }
        }
        return maxGold;
    }
    
    int findMaxGold(vector<vector<int>>& grid, int m, int n, int x, int y) {
        if(x < 0 || y < 0 || y == n || x == m || grid[x][y] == 0)
              return 0;
        int tmp = grid[x][y];
        // mark as visited
        grid[x][y] = 0;
        int maxGold = 0;
        for(int i = 0; i < 4; i++) {
            maxGold = max(maxGold, findMaxGold(grid, m, n, x + way[i], y + way[i+1]));
        }
        // backtrack
        grid[x][y] = tmp; 
        return tmp + maxGold;
    }
};

