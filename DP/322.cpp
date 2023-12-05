#include "include.h"


class Solution {
public:
    int DFS(vector<int>& nums, int target, int cur_idx) {
        if(cur_idx < 0) {
            if(target == 0)
                return 0;
            else
                return INT_MAX / 2;
        }
        if(target < nums[cur_idx])
            return DFS(nums, target, cur_idx - 1);
        return min(DFS(nums, target, cur_idx - 1), DFS(nums, target - nums[cur_idx], cur_idx) + 1);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = DFS(coins, amount, n - 1);
        if(ans == INT_MAX / 2)
            return -1;
        return ans;
    }
};


class Solution {
public:
    int DFS(vector<int>& nums, vector<vector<int>>&memo, int target, int cur_idx) {
        if(cur_idx < 0) {
            if(target == 0)
                return 0;
            else
                return INT_MAX / 2;
        }
        int &res = memo[target][cur_idx];
        if(res != -1)
            return res;

        if(target < nums[cur_idx])
            return  res = DFS(nums, memo, target, cur_idx - 1);
        return res = min(DFS(nums, memo, target, cur_idx - 1), DFS(nums, memo, target - nums[cur_idx], cur_idx) + 1);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> memo(amount + 1, vector<int>(n + 1, -1));
        int ans = DFS(coins, memo, amount, n - 1);
        if(ans == INT_MAX / 2)
            return -1;
        return ans;
    }
};

// Space Optimization
class Solution {
public:
    int coinChange(vector<int>& nums, int target) {
        int n = nums.size();
        int dp[n + 1][target + 1];
        memset(dp, INT_MAX / 2, sizeof(dp));
        dp[0][0] = 0;

        for(int i = 0; i < n; i++) {
            for(int c = 0; c < target + 1; c++) {
                if(c < nums[i])
                    dp[i + 1][c] = dp[i][c];
                else
                    dp[i + 1][c] = min(dp[i][c], dp[i + 1][c - nums[i]] + 1);
            }
            
        }
        if(dp[n][target] == INT_MAX / 2)
            return -1;
        return dp[n][target];
    }
};

// Space Optimization: one-dimensional array
class Solution {
public:
    int coinChange(vector<int>& nums, int target) {
        int n = nums.size();
        int dp[target + 1];
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;

        for(int i = 0; i < n; i++) {
            for(int c = 0; c < target + 1; c++) {
                if(c < nums[i])
                    dp[c] = dp[c];
                else
                    dp[c] = min(dp[c], dp[c - nums[i]] + 1);
            }
        }
        int ans = dp[target];
        if(ans >= 0x3f3f3f3f)
            return -1;
        return ans;
    }
};