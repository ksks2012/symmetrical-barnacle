#include "include.h"
    
class Solution {
public:
    bool check(const vector<int>& nums, long long k) {
        long long ops = 0;
        for (long long x : nums) {
            ops += (x + k - 1) / k;
            if (ops > k * k)
                return false;
        }

        return true;
    }

    int minimumK(vector<int>& nums) {
        long long maxi = *max_element(nums.begin() , nums.end()) ;
        long long left = 1;
        long long right = max<long long>(maxi, nums.size());

        while (left < right) {
            long long mid = left + (right - left) / 2;

            if (check(nums, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
