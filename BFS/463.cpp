#include "../include.h"

class Solution {
public:
    vector<int> way = {1, 0, -1, 0, 1};
    int m = 0;
    int n = 0;
    int getPerimeter(vector<vector<int>>& grid, int x, int y) {
        if(x < 0 || x >= m || y < 0 || y >= n) {
            return 1;
        }

        if (grid[x][y] == 0)
            return 1;
        if (grid[x][y] == -1) 
            return 0;

        int count = 0;
        grid[x][y] = -1;

        for(int k = 0; k < 4; k++) {
            count += getPerimeter(grid, x + way[k], y + way[k + 1]);
        }
        return count;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int one_count = 0;
        int near_count = 0;
        m = grid.size();
        n = grid[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    return getPerimeter(grid, i, j);
                } 
            }
        }

        return 0;
    }
};

class Solution {
public:
    vector<int> way = {1, 0, -1, 0, 1};
    int islandPerimeter(vector<vector<int>>& grid) {
        int one_count = 0;
        int near_count = 0;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    one_count++;
                    for(int k = 0; k < 4; k++) {
                        int tmp_x = i + way[k];
                        int tmp_y = j + way[k + 1];
                        if(tmp_x < 0 || tmp_x >= m || tmp_y < 0 || tmp_y >= n) {
                            continue;
                        }
                        if(grid[tmp_x][tmp_y] == 1) {
                            near_count++;
                        }
                    }
                } 
            }
        }

        return one_count * 4 - near_count;
    }
};