#include "include.h"

// TLE
class Solution {
public:
    int n = 0;
    int DFS(vector<int>& nums, int idx, int target) {
        if(idx == n - 1) {
            return 0;
        }
        
        int res = INT_MIN;
        for(int i = idx + 1; i < n; i++) {
            if(abs(nums[idx] - nums[i]) <= target)
                res = max(res, 1 + DFS(nums, i, target));
        }

        return res;
    }

    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();
        if(target == 0) {
            return -1;
        }

        int res = DFS(nums, 0, target);
        return res > 0 ? res : -1;
    }
};

class Solution {
public:
    int n = 0;
    int DFS(vector<int>& nums, int idx, int target, vector<int> &dp) {
        if(idx == n - 1) {
            return 0;
        }

        if(dp[idx] != -1) {
            return dp[idx];
        }

        int res = INT_MIN;
        for(int i = idx + 1; i < n; i++) {
            if(abs(nums[idx] - nums[i]) <= target)
                res = max(res, 1 + DFS(nums, i, target, dp));
        }

        return dp[idx] = res;
    }

    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();

        vector<int> dp(n, -1);
        int res = DFS(nums, 0, target, dp);

        return res > 0 ? res : -1;
    }
};