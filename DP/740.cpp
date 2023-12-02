#include "include.h"

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> tmp(10002);
        for(int i = 0;i < nums.size(); i++) {
            tmp[nums[i]] += nums[i];
        }
        vector<int> dp(10002);
        dp[1] = tmp[1];
        dp[2] = max(tmp[1], tmp[2]);
        for(int i = 3; i < dp.size(); i++){
            dp[i] = max(dp[i - 2] + tmp[i], dp[i - 1]);
        }

        return max(dp[10000], dp[9999]);
    }
};