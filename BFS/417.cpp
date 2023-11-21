#include "include.h"

class Solution {
public:
    int m;
    int n;
    vector<int> way{-1, 0, 1, 0, -1};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }
        vector<vector<int>> ans;
        m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> can_reach_p(m, vector<bool>(n, false));
        vector<vector<bool>> can_reach_a(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            DFS(matrix, can_reach_p, i, 0);
            DFS(matrix, can_reach_a, i, n - 1);
        }
        for (int i = 0; i < n; ++i) {
            DFS(matrix, can_reach_p, 0, i);
            DFS(matrix, can_reach_a, m - 1, i);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; ++j) {
                if (can_reach_p[i][j] && can_reach_a[i][j]) {
                ans.push_back(vector<int>{i, j});
                }
            }
        }
        return ans;
    }

    void DFS(const vector<vector<int>>& matrix, vector<vector<bool>>& can_reach, int r, int c) {
        if (can_reach[r][c]) {
            return;
        }
        can_reach[r][c] = true;
        int x, y;
        for (int i = 0; i < 4; ++i) {
            x = r + way[i];
            y = c + way[i + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && matrix[r][c] <= matrix[x][y]) {
                DFS(matrix, can_reach, x, y);
            }
        }
    }

};