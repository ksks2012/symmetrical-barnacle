#include "include.h"

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;
        backtracking(nums, target, ans, 0, 0);
        return ans;
    }

    void backtracking(vector<int>& nums, int target, int &ans, int cur_idx, int cur_sum) {
        if(cur_idx == nums.size()) {
            if(cur_sum == target) {
                ans++;
            }
            return;
        }
        int tmp = cur_sum;
        backtracking(nums, target, ans, cur_idx + 1, tmp + nums[cur_idx]);
        backtracking(nums, target, ans, cur_idx + 1, tmp - nums[cur_idx]);

    }
};

class Solution {
public:
    int DFS(vector<int>& nums, int target, int cur_idx) {
        if(cur_idx < 0) {
            if(target == 0)
                return 1;
            else
                return 0;
        }
        if(target < nums[cur_idx])
            return DFS(nums, target, cur_idx - 1);
        return DFS(nums, target, cur_idx - 1) + DFS(nums, target - nums[cur_idx], cur_idx - 1);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        // p
        // s - p
        // p - (s - p) = t
        // 2p = s + t
        // p = (s + t) // 2
        for(int i = 0; i < n; i++) {
            target += nums[i];
        }
        if(target < 0 || target % 2) {
            return 0;
        }
        target /= 2;
        return DFS(nums, target, n - 1);
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            target += nums[i];
        }
        if(target < 0 || target % 2) {
            return 0;
        }
        target /= 2;

        int dp[n + 1][target + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        for(int i = 0; i < n; i++) {
            for(int c = 0; c < target + 1; c++) {
                if(c < nums[i])
                    dp[i + 1][c] = dp[i][c];
                else
                    dp[i + 1][c] = dp[i][c] + dp[i][c - nums[i]];
            }
            
        }
        return dp[n][target];
    }
};

// Space Optimization
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            target += nums[i];
        }
        if(target < 0 || target % 2) {
            return 0;
        }
        target /= 2;

        int dp[2][target + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        for(int i = 0; i < n; i++) {
            for(int c = 0; c < target + 1; c++) {
                if(c < nums[i])
                    dp[(i + 1) % 2][c] = dp[i % 2][c];
                else
                    dp[(i + 1) % 2][c] = dp[i % 2][c] + dp[i % 2][c - nums[i]];
            }
            
        }
        return dp[n % 2][target];
    }
};

// Space Optimization: one-dimensional array
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            target += nums[i];
        }
        if(target < 0 || target % 2) {
            return 0;
        }
        target /= 2;

        int dp[target + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        for(int i = 0; i < n; i++) {
            for(int c = target; c >= nums[i]; c--) {
                dp[c] = dp[c] + dp[c - nums[i]];
            }
            
        }
        return dp[target];
    }
};

