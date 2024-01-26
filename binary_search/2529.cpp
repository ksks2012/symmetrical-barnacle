#include "include.h"

class Solution {
public:
    int lower_bound(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(target == nums[mid]) {
                right = mid - 1;
            }
            else if(target < nums[mid])
                right = mid - 1;
            else 
                left = mid + 1;
        }
        return right;
    }

    int upper_bound(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(target == nums[mid]) {
                left = mid + 1;
            }
            else if(target < nums[mid])
                right = mid - 1;
            else 
                left = mid + 1;
        }
        return left;
    }

    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int lower = lower_bound(nums, 0);
        int upper = upper_bound(nums, 0);

        return max(lower + 1, n - upper);
    }
};