#include "include.h"

// DFS: TLE
class Solution {
public:
    vector<int> prices;
    int DFS(int i, int hold) {
        if(i < 0) {
            if(hold)
                return -1 * INT_MAX / 2;
            return 0;
        }
            

        if(hold)
            return max(DFS(i - 1, 1), DFS(i - 1, 0) - prices[i]);
        
        return max(DFS(i - 1, 0), DFS(i - 1, 1) + prices[i]);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        this->prices = prices;
        return DFS(n - 1, 0);
    }
};

// DFS with memory
class Solution {
public:
    vector<int> prices;
    int DFS(int i, int hold, vector<vector<int>> &memo) {
        if(i < 0) {
            if(hold)
                return -1 * INT_MAX / 2;
            return 0;
        }

        int &res = memo[i][hold];
        if(res != -1)
            return res;            

        if(hold)
            return res = max(DFS(i - 1, 1, memo), DFS(i - 1, 0, memo) - prices[i]);
        
        return res = max(DFS(i - 1, 0, memo), DFS(i - 1, 1, memo) + prices[i]);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        this->prices = prices;
        vector<vector<int>> memo(n + 1, vector<int>(2, -1));
        return DFS(n - 1, 0, memo);
    }
};

// Iteration
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        dp[0][0] = 0;
        dp[0][1] = -1 * INT_MAX / 2;

        for(int i = 0; i < n; i++) {
            dp[i + 1][0] = max(dp[i][0], dp[i][1] + prices[i]);
            dp[i + 1][1] = max(dp[i][1], dp[i][0] - prices[i]);
        }

        return dp[n][0];
    }
};

// Space Optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int dp0 = 0;
        int dp1 = -1 * INT_MAX / 2;

        for(int i = 0; i < n; i++) {
            int dp0_tmp = max(dp0, dp1 + prices[i]);
            int dp1_tmp = max(dp1, dp0 - prices[i]);
            dp0 = dp0_tmp;
            dp1 = dp1_tmp;
        }

        return dp0;
    }
};