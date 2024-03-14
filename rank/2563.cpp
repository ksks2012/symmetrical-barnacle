#include "include.h"

class Solution {
public:
    long long two_pointer(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        long long res = 0;
        while(left < right) {
            while(left < right && nums[left] + nums[right] > target) {
                right--;
            }
            res += right - left;
            left++;
        }
        return res;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());

        return two_pointer(nums, upper) - two_pointer(nums, lower - 1);
    }
};