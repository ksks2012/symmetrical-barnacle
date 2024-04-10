#include "include.h"

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long left_sum = 0, right_sum = 0;;
        int left_zero = 0, right_zero;
        for(auto n : nums1) {
            left_sum += n;
            if(n == 0) {
                left_zero++;
            }
        }

        for(auto n : nums2) {
            right_sum += n;
            if(n == 0) {
                right_zero++;
            }
        }

        long long res = 0;
        if(left_zero == 0 && left_sum < right_sum + right_zero)
            return -1;
        if(right_zero == 0 && right_sum < left_sum + left_zero)
            return -1;

        return max(left_sum + left_zero, right_sum + right_zero);
    }
};