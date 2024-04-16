#include "include.h"

// BFS
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;
        minHeap.emplace(0, 0, 0);
        dist[0][0] = 0;
        
        int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while (!minHeap.empty()) {
            auto [effort, x, y] = minHeap.top();
            minHeap.pop();
            
            if (effort > dist[x][y]) 
                continue;
            
            if (x == rows - 1 && y == cols - 1) 
                return effort;
            
            // Try 4 ways
            for (auto& dir : directions) {
                int next_x = x + dir[0], next_y = y + dir[1];
                if (next_x >= 0 && next_x < rows && next_y >= 0 && next_y < cols) {
                    int new_effort = max(effort, abs(heights[x][y] - heights[next_x][next_y]));
                    // minimum effort
                    if (new_effort < dist[next_x][next_y]) {
                        dist[next_x][next_y] = new_effort;
                        minHeap.emplace(new_effort, next_x, next_y);
                    }
                }
            }
        }
        return -1;
    }
};