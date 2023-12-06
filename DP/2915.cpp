#include "include.h"

// TLE
class Solution {
public:
    int DFS(vector<int>& nums, int target, int cur_idx, int cur_len) {
        if(target < 0)
            return 0;
        if(cur_idx < 0) {
            if(target == 0)
                return cur_len;
            else
                return 0;
        }
        if(target < nums[cur_idx])
            return DFS(nums, target, cur_idx - 1, cur_len);
        return max(DFS(nums, target, cur_idx - 1, cur_len), DFS(nums, target - nums[cur_idx], cur_idx - 1, cur_len + 1));
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = DFS(nums, target, n - 1, 0);
        if(ans == 0)
            return -1;
        return ans;
    }
};

// TLE
class Solution {
public:
    int DFS(vector<int>& nums, int target, int cur_idx, int cur_len, vector<vector<vector<int>>>& memo) {
        if(target < 0)
            return 0;
        if(cur_idx < 0) {
            if(target == 0)
                return cur_len;
            else
                return 0;
        }
        int &res = memo[target][cur_idx][cur_len];
        if(res != -1) {
            return res;
        }
        if(target < nums[cur_idx])
            return res = DFS(nums, target, cur_idx - 1, cur_len, memo);
        return res = max(DFS(nums, target, cur_idx - 1, cur_len, memo), DFS(nums, target - nums[cur_idx], cur_idx - 1, cur_len + 1, memo));
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<vector<int>>> memo(target + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
        int ans = DFS(nums, target, n - 1, 0, memo);
        if(ans == 0)
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