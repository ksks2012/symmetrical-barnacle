#include "include.h"

// DFS: TLE
class Solution {
public:
    vector<int> prices;
    int DFS(int i, int k, int hold) {
        if(k < 0) 
            return INT_MIN / 2; 
        if(i < 0) {
            if(hold)
                return INT_MIN / 2;
            return 0;
        }
        
        if(hold)
            return max(DFS(i - 1, k, 1), DFS(i - 1, k - 1, 0) - prices[i]);
        
        return max(DFS(i - 1, k, 0), DFS(i - 1, k, 1) + prices[i]);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        this->prices = prices;
        return DFS(n - 1, 2, 0);
    }
};

// DFS with memo: TLE
class Solution {
public:
    vector<int> prices;
    int DFS(int i, int k, int hold, vector<vector<vector<int>>>& memo) {
        if(k < 0) 
            return INT_MIN / 2; 
        if(i < 0) {
            if(hold)
                return INT_MIN / 2;
            return 0;
        }

        int &res = memo[i][k][hold];
        if(res != -1)
            return res;
        
        if(hold)
            return res = max(DFS(i - 1, k, 1, memo), DFS(i - 1, k - 1, 0, memo) - prices[i]);
        
        return res = max(DFS(i - 1, k, 0, memo), DFS(i - 1, k, 1, memo) + prices[i]);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        this->prices = prices;
        int k = 2;
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));
        return DFS(n - 1, k, 0, memo);
    }
};

// Iteration
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k = 2;
        int n = prices.size();
        
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 2, vector<int>(2, INT_MIN / 2)));
        for(int j = 1; j < k + 2; j++) {
            dp[0][j][0] = 0;
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < k + 2; j++) {
                dp[i + 1][j][0] = max(dp[i][j][0], dp[i][j - 1][1] + prices[i]);
                dp[i + 1][j][1] = max(dp[i][j][1], dp[i][j][0] - prices[i]);
            }

        }
        return dp[n][k + 1][0];
    }
};

// Space Optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2;
        
        vector<vector<int>> dp(k + 2, vector<int>(2, INT_MIN / 2));
        for(int j = 1; j <= k + 1; j++) {
            dp[j][0] = 0;
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = k + 1; j > 0; j--) {
                dp[j][0] = max(dp[j][0], dp[j - 1][1] + prices[i]);
                dp[j][1] = max(dp[j][1], dp[j][0] - prices[i]);
            }

        }
        return dp[k + 1][0];
    }
};
