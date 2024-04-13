#include "../include.h"

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long res = 0;

        int n = nums.size();
        int left = 0;
        long long cur = 0;

        for(int right = 0; right < n; right++) {
            cur += nums[right];
            while(cur * (right - left + 1) >= k) {
                cur -= nums[left];
                left++;
            }
            res += (right - left + 2) / 2;
        }	

        return res;
    }
};