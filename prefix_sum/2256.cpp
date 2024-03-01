#include "include.h"

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long right = 0;
        long long left = 0;

        for(int i = 0; i < n; i++) {
            right += nums[i];
        }

        int mini = INT_MAX;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            left += nums[i];
            right -= nums[i];
            
            long long left_result = left / (i + 1);
            long long right_result = (i == n - 1) ? 0 : (right / (n - i - 1));
            long long tmp = abs(left_result - right_result);
            if(tmp < mini) {
                mini = tmp;
                ans = i;
            }
        }

        return ans;
    }
};