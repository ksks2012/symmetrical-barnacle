#include "include.h"

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int res = 0;

        for(int i = 1; i < nums.size(); i++) {
            // Calculate the absolute difference between adjacent elements
            int diff = abs(nums[i] - nums[i - 1]);
            // Update the result if the current difference is greater
            if(diff > res) {
                res = diff;
            }
        }

        res = max(res, abs(nums[0] - nums[nums.size() - 1]));

        return res;
    }
};