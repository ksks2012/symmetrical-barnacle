#include "include.h"

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> left_sum(n, 0);
        vector<int> right_sum(n, 0);

        int left_tmp = 0, right_tmp = 0;
        for(int i = 0; i < n; i++) {
            left_sum[i] = left_tmp;
            left_tmp += nums[i];

            right_sum[n - i - 1] = right_tmp;
            right_tmp += nums[n - i - 1];
        }

        vector<int> ans(n, 0);
        for(int i = 0;  i < n; i++) {
            ans[i] = abs(left_sum[i] - right_sum[i]);
        }
    
        return ans;
    }
};