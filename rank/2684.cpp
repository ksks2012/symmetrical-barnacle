#include "include.h"

// DFS
class Solution {
public:
    int m, n;
    int DFS(vector<vector<int>>& grid, int x, int y, int prev) {
        if(x < 0 || y < 0 || x >= m || y >= n || grid[x][y] <= prev) {
            return -1;
        }
        int res = 0;
        // (row, col + 1)
        res = max(res, DFS(grid, x, y + 1, grid[x][y]) + 1);

        // (row - 1, col + 1)
        res = max(res, DFS(grid, x - 1, y + 1, grid[x][y]) + 1);
        
        // (row + 1, col + 1)
        res = max(res, DFS(grid, x + 1, y + 1, grid[x][y]) + 1);
        return res;
    }

    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int res = 0;
        for(int i = 0; i < m; i++) {
            res = max(res, DFS(grid, i, 0, -1));
        }

        return res;
    }
};

// DFS optimization
class Solution {
public:
    int m, n;
    int DFS(vector<vector<int>>& grid, int x, int y, int prev) {
        if(x < 0 || y < 0 || x >= m || y >= n || grid[x][y] <= prev) {
            return -1;
        }
        int res = 0;
        // (row, col + 1)
        res = max(res, DFS(grid, x, y + 1, grid[x][y]) + 1);

        // (row - 1, col + 1)
        res = max(res, DFS(grid, x - 1, y + 1, grid[x][y]) + 1);
        
        // (row + 1, col + 1)
        res = max(res, DFS(grid, x + 1, y + 1, grid[x][y]) + 1);

        grid[x][y] = 0;
        return res;
    }

    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int res = 0;
        for(int i = 0; i < m; i++) {
            res = max(res, DFS(grid, i, 0, -1));
        }

        return res;
    }
};

// DFS with memory
class Solution {
public:
    int m, n;
    int dp[1001][1001];
    int DFS(vector<vector<int>>& grid, int x, int y, int prev) {
        if(x < 0 || y < 0 || x >= m || y >= n || grid[x][y] <= prev) {
            return -1;
        }
        int &res = dp[x][y];
        if(res != -1)
            return res;
        // (row, col + 1)
        res = max(res, DFS(grid, x, y + 1, grid[x][y]) + 1);

        // (row - 1, col + 1)
        res = max(res, DFS(grid, x - 1, y + 1, grid[x][y]) + 1);
        
        // (row + 1, col + 1)
        res = max(res, DFS(grid, x + 1, y + 1, grid[x][y]) + 1);

        return res;
    }

    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        memset(dp, -1, sizeof(dp));
        int res = 0;
        for(int i = 0; i < m; i++) {
            res = max(res, DFS(grid, i, 0, -1));
        }

        return res;
    }
};