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