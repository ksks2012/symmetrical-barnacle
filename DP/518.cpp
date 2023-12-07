#include "include.h"

// TLE
class Solution {
public:
    int DFS(vector<int>& nums, int target, int cur_idx) {
        if(cur_idx < 0) {
            if(target == 0)
                return 1;
            else
                return 0;
        }
        if(target < nums[cur_idx]) {
            return DFS(nums, target, cur_idx - 1);
        }

        return DFS(nums, target - nums[cur_idx], cur_idx) + DFS(nums, target, cur_idx - 1);
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return DFS(coins, amount, n - 1);
    }
};

class Solution {
public:
    int DFS(vector<int>& nums, int target, int cur_idx, vector<vector<int>> &memo) {
        if(cur_idx < 0) {
            if(target == 0)
                return 1;
            else
                return 0;
        }
        int &res = memo[target][cur_idx];
        if(res != -1)
            return res;
        if(target < nums[cur_idx]) {
            return res = DFS(nums, target, cur_idx - 1, memo);
        }

        return res = DFS(nums, target - nums[cur_idx], cur_idx, memo) + DFS(nums, target, cur_idx - 1, memo);
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> memo(amount + 1, vector<int>(n + 1, -1));
        return DFS(coins, amount, n - 1, memo);
    }
};

// Space Optimization
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int dp[n + 1][amount + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < amount + 1; j++) {
                if(j < coins[i]) {
                    dp[i + 1][j] = dp[i][j];
                } else {
                    dp[i + 1][j] = dp[i][j] + dp[i + 1][j - coins[i]];
                }
            }
        }
        return dp[n][amount];
    }
};

// Space Optimization: one-dimensional array
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int dp[amount + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < amount + 1; j++) {
                if(j > coins[i]) {
                    dp[j] = dp[j] + dp[j - coins[i]];
                }
            }
        }
        return dp[amount];
    }
};