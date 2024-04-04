#include "include.h"

class Solution {
public:
    vector<int> way = {1, 0, -1, 0, 1};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int res = 0;

        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                if ((x != entrance[0] || y != entrance[1]) && (x == 0 || y == 0 || x == maze.size() - 1 || y == maze[0].size() - 1)) {
                    return res;
                }
                for (int j = 0; j < 4; j++) {
                    int nx = x + way[j];
                    int ny = y + way[j + 1];
                    if (nx >= 0 && nx < maze.size() && ny >= 0 && ny < maze[0].size() && maze[nx][ny] == '.') {
                        maze[nx][ny] = '+';
                        q.push({nx, ny});
                    }
                }
            }
            res++;
        }
        
        return -1;
    }
};