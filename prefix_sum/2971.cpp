#include "include.h"

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        long long cur = 0;

        long long maxi = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(cur > nums[i] && i >= 2) {
                maxi = max(maxi, cur + nums[i]);
            }   
            cur += nums[i];
        }
        return maxi;
    }
};