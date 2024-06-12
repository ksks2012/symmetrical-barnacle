#include "include.h"

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int res = 0;


        int m = grid.size();
        int n = grid[0].size();


        priority_queue<int> pq[m];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                pq[i].push(grid[i][j]);
            }
        }

        while(!pq[0].empty()) {
            int maxi = 0;
            for(int i = 0; i < m; i++) {
                maxi = max(maxi, pq[i].top());
                pq[i].pop();
            }
            res += maxi;
        }

        return res;
    }
};