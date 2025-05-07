#include "include.h"

class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        auto populateDiag = [&](int i, int j) {
            unordered_set<int> top_left, bottom_right;
            for (int d = 0; i + d < m && j + d < n; ++d) {
                res[i + d][j + d] = top_left.size();
                top_left.insert(g[i + d][j + d]);
            }
            for (int d = min(m - i, n - j) - 1; d >= 0; --d) {
                res[i + d][j + d] = abs(res[i + d][j + d] - (int)bottom_right.size());
                bottom_right.insert(g[i + d][j + d]);            
            }
        };
        for (int j = 0; j < n; ++j)
            populateDiag(0, j);
        for (int i = 1; i < m; ++i)
            populateDiag(i, 0);
        return res;
    }
};