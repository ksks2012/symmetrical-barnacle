#include "include.h"

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long res = 0;

        int left = 0;
        long long tmp = 0;
        for(int right = 0; right < n; right++) {
            tmp += nums[right];
            while(tmp * (right - left + 1) >= k) {
                tmp -= nums[left];
                left++;
            }
            res += right - left + 1;
        }

        return res;
    }
};