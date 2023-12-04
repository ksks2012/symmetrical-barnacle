#include "include.h"

// TLE
class Solution {
public:
    int DFS(vector<int> &nums, int cur) {
        if(cur < 0) 
            return 0;

        return max(DFS(nums, cur - 1), DFS(nums, cur - 2) + nums[cur]);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        return DFS(nums, n - 1);
    }
};


class Solution {
public:
    int DFS(vector<int> &nums, vector<int> &memo, int cur) {
        if(cur < 0) 
            return 0;
        if(memo[cur] != -1)
            return memo[cur];
        
        memo[cur] = max(DFS(nums, memo, cur - 1), DFS(nums, memo, cur - 2) + nums[cur]);

        return memo[cur];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n + 1, -1);

        return DFS(nums, memo, n - 1);
    }
};


class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 2, 0);
        
        for(int i = 0; i < n; i++) {
            dp[i + 2] = max(dp[i] + nums[i], dp[i + 1]);
        }

        return dp[n + 1];
    }
};

// Space optimization
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int f0 = 0, f1 = 0;
        
        for(int i = 0; i < n; i++) {
            int tmp = max(f0 + nums[i], f1);
            f0 = f1;
            f1 = tmp;
        }

        return f1;
    }
};
