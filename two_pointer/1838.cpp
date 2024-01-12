#include "include.h"

// lee
class Solution {
public:
    int maxFrequency(vector<int>& nums, long k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int left = 0, right = 0;
        for(; right < n; right++) {
            k += nums[right];
            if(k < (long)nums[right] * (right - left + 1))
                k -= nums[left++];
        }
        return right - left;
    }
};