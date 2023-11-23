#include "../include.h"

class Solution {
public:
    vector<int> way = {1, 0, -1, 0, 1};
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;

        vector<vector<int>> visited = grid;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 1) 
                    q.push({i, j});
            }
        }
        if (q.empty() || q.size() == n * n) 
            return -1;

        int level = -1;
        // visit all four direction i.e. right, left, up, down
        while (!q.empty()) {
            int q_size = q.size();
            for(int i = 0; i < q_size; i++) {
                auto [x, y] = q.front();
                q.pop();
                for (int j = 0; j < 4; j++) {
                    int tmp_x = x + way[j];
                    int tmp_y = y + way[j + 1];
                    if (tmp_x >= 0 && tmp_x < n && tmp_y >= 0 && tmp_y < n && visited[tmp_x][tmp_y] == 0) {
                        visited[tmp_x][tmp_y] = 1;
                        q.push({tmp_x, tmp_y});
                    }
                }
            }
            level++;
        }
        return level;
    }
};

