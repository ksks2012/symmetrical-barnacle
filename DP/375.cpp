#include "include.h"

// DFS
class Solution {
public:
    int DFS(int i, int j) {
        if(i >= j)
            return 0;

        int tmp = INT_MAX / 3;
        for(int k = i; k <= j; k++) {
            tmp = min(tmp, max(DFS(i, k - 1), DFS(k + 1, j)) + k);
        }
        return tmp;
    }

    int getMoneyAmount(int n) {
        return DFS(0, n); 
    }
};

// DFS with memory
class Solution {
public:
    int DFS(int i, int j, vector<vector<int>> &memo) {
        if(i >= j)
            return 0;

        int &res = memo[i][j];
        if(res != -1)
            return res;

        int tmp = INT_MAX / 3;
        for(int k = i; k <= j; k++) {
            tmp = min(tmp, max(DFS(i, k - 1, memo), DFS(k + 1, j, memo)) + k);
        }
        return res = tmp;
    }

    int getMoneyAmount(int n) {
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
        return DFS(0, n, memo); 
    }
};


// Iteration
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));

        for(int i = 0; i <= n; i++){
            dp[i][i] = 0;
        }

        for(int j = 2; j <= n; j++) {
            for(int i = j - 1; i >= 1; i--) {
                for(int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], max(dp[i][k - 1], dp[k + 1][j]) + k);
                }
                dp[i][j] = min(dp[i][j], i + dp[i + 1][j]);
                dp[i][j] = min(dp[i][j], j + dp[i][j - 1]);
            }
        }

        return dp[1][n];
    }
};