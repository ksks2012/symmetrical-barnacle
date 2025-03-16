#include "../include.h"


class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size();
        int res = 0;

        int j = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != nums[j] + (i - j) % 2) {
                j = i - (nums[i - 1]  == nums[i] - 1); 
            }
            res = max(res, i - j + 1);
        }

        return res == 1 ? -1 : res;
    }
};