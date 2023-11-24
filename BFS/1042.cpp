#include "../include.h"

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> ans(n);
        vector<vector<int>> graph(n);
        for (vector<int>& p : paths) {
            graph[p[0] - 1].push_back(p[1] - 1);
            graph[p[1] - 1].push_back(p[0] - 1);
        }

        for (int i = 0; i < n; ++i) {
            int colors[5] = {};
            // For each path from node
            for (int j : graph[i]) {
                //Mark the color as used if neighbor has used it before.
                colors[ans[j]] = 1;
            }
            // Use a color that has not been used yet
            for (int c = 4; c > 0; --c)
                if (!colors[c])
                    ans[i] = c;
        }
        return ans;
    }
};