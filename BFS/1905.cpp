#include "../include.h"

class Solution {
public:
    int m = 0;
    int n = 0;
    vector<int> way = {1, 0, -1, 0, 1};

    void DFS(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int x, int y, bool &is_sub) {
        // edge
        if(x < 0 || y < 0 || x >= m || y >= n)
            return;
        if(grid2[x][y] == 0) 
            return;

        if(grid1[x][y] != 1 && grid2[x][y] == 1) {
            is_sub = false;
            return;
        }

        // visited
        grid1[x][y] = 0;
        grid2[x][y] = 0;

        // DFS 4 ways
        for(int i = 0; i < 4; i++) {
            int tmp_x = x + way[i];
            int tmp_y = y + way[i + 1];
            DFS(grid1, grid2, tmp_x, tmp_y, is_sub);
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        // init m, n
        m = grid1.size();
        n = grid1[0].size();

        int count = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // start finding when grid[i][j] is 1
                if(grid2[i][j] == 1 && grid1[i][j] == 1) {
                    bool is_sub = true;
                    DFS(grid1, grid2, i, j, is_sub);
                    if(is_sub)
                        count++;
                }
            }
        }
        return count;
    }
};

// Optimization: DFS return
class Solution {
public:
    int m = 0;
    int n = 0;
    vector<int> way = {1, 0, -1, 0, 1};

    int DFS(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int x, int y) {
        if(x < 0 || y < 0 || x >= m || y >= n)
            return 1;
        if(grid2[x][y] == 0) 
            return 1;

        grid2[x][y] = 0;

        int res = 1;
        for(int i = 0; i < 4; i++) {
            int tmp_x = x + way[i];
            int tmp_y = y + way[i + 1];
            res &= DFS(grid1, grid2, tmp_x, tmp_y);
        }
        return res & grid1[x][y];
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();

        int count = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid2[i][j] == 1 && grid1[i][j] == 1) {
                    count += DFS(grid1, grid2, i, j);
                }
            }
        }
        return count;
    }
};