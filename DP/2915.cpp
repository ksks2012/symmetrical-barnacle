#include "include.h"

// TLE
class Solution {
public:
    int DFS(vector<int>& nums, int target, int cur_idx) {
        if(cur_idx < 0) {
            if(target == 0)
                return 0;
            else
                return INT_MAX / 2 * -1;
        }
        if(target < nums[cur_idx])
            return DFS(nums, target, cur_idx - 1);
        return max(DFS(nums, target, cur_idx - 1), DFS(nums, target - nums[cur_idx], cur_idx - 1) + 1);
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = DFS(nums, target, n - 1);
        if(ans < 0)
            return -1;
        return ans;
    }
};

// memo
class Solution {
public:
    int DFS(vector<int>& nums, int target, int cur_idx, vector<vector<int>> &memo) {
        if(cur_idx < 0) {
            if(target == 0)
                return 0;
            else
                return INT_MAX / 2 * -1;
        }
        int &res = memo[target][cur_idx];
        if(res != -1)
            return res;
        if(target < nums[cur_idx])
            return res = DFS(nums, target, cur_idx - 1, memo);
        return res = max(DFS(nums, target, cur_idx - 1, memo), DFS(nums, target - nums[cur_idx], cur_idx - 1, memo) + 1);
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> memo(target + 1, vector<int>(n + 1, -1));
        int ans = DFS(nums, target, n - 1, memo);
        if(ans < 0)
            return -1;
        return ans;
    }
};



class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        int max_len = 0;

        int dp[n + 1][target + 1];
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n + 1; i++)
            dp[i][0] = 0; // Longest subsequence when the target sum is 0.


        for(int i = 0; i < n; i++) {
            for(int c = 0; c < target + 1; c++) {
                dp[i + 1][c] = dp[i][c];
                if (c >= nums[i] && dp[i][c - nums[i]] != -1)
                    dp[i + 1][c] = max(1 + dp[i][c - nums[i]], dp[i][c]);
            }
        }
        
        return dp[n][target];
    }
};

// Space Optimization
class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        int max_len = 0;

        int dp[target + 1];
        memset(dp, -1, sizeof(dp));
        dp[0] = 0; // Longest subsequence when the target sum is 0.

        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum = min(sum + nums[i], target);
            for(int c = sum; c >= nums[i]; c--) {
                if (c >= nums[i] && dp[c - nums[i]] != -1)
                    dp[c] = max(1 + dp[c - nums[i]], dp[c]);
            }
        }
        
        return dp[target];
    }
};