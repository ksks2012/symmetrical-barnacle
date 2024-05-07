#include "include.h"

class Solution {
public:
    int m, n;

    int DFS(vector<vector<int>> &freq, int cur, int prev, vector<vector<int>> &dp) {
        if(cur == -1) {
            return 0;
        }
        int &res = dp[cur][prev];
        if(res != INT_MAX)
            return res;

        for(int i = 0; i < 10; i++) {
            if(i == prev) {
                continue;
            }
            int tmp = m - freq[cur][i];
            res = min(res, tmp + DFS(freq, cur - 1, i, dp));
        }
        if(res == INT_MAX)
            return 0;
        return res;
    }

    int minimumOperations(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> freq(n, vector<int>(10, 0));
        vector<vector<int>> dp(n, vector<int>(10, INT_MAX));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                freq[j][grid[i][j]]++;
            }
        }

        int res = INT_MAX;
        for(int i = 0; i < 10; i++) {
            res = min(res, m - freq[n - 1][i] + DFS(freq, n - 2, i, dp));
        }
        
        return res;
    }
};

// endlesscheng
class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<array<int, 10>> count(n);
        for (auto& row : grid) {
            for (int j = 0; j < n; j++) {
                count[j][row[j]]++;
            }
        }

        // -1: not calculated
        vector<vector<int>> memo(n, vector<int>(11, -1));
        function<int(int, int)> DFS = [&](int i, int j) -> int {
            if (i < 0) {
                return 0;
            }
            // using memory
            auto& res = memo[i][j];
            if (res != -1) {
                return res;
            }

            res = 0;
            for (int k = 0; k < 10; k++) {
                if (k != j) {
                    res = max(res, DFS(i - 1, k) + count[i][k]);
                }
            }
            return res;
        };
        // m * n - unchanged block
        return m * n - DFS(n - 1, 10);
    }
};

class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), dp[2][10] = {};
        for (int i = 1; i <= n; ++i) {
            int freq[10] = {};
            for (int j = 0; j < m; ++j)
                ++freq[grid[j][i - 1]];
            for (int x = 0; x < 10; ++x)
                for (int y = 0; y < 10; ++y)
                    if (y != x)
                        dp[i % 2][x] = max(dp[i % 2][x], freq[x] + dp[!(i % 2)][y]);
        }
        return n * m - *max_element(begin(dp[n % 2]), end(dp[n % 2]));
    }
};