#include "../include.h"

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size() < 2) {
            return true;
        }
        if(nums.size() == 2) {
            return (nums[0] + nums[1]) % 2 == 1;
        }

        int n = nums.size();
        for(int i = 0; i < n - 1; i++) {
            if((nums[i] + nums[i + 1]) % 2 != 1) {
                return false;
            }
        }
        return true;
    }
};