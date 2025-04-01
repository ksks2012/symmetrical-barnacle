#include "include.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {        
        int res = nums[0];
        int sum =  nums[0];
        
        for(auto i = 1; i < nums.size(); ++i) {
            
            if(nums[i] > sum && sum < 0)
                sum = nums[i];
            else
                sum += nums[i];
            res = max(sum, res);
            
        }
        return res;
    }
};