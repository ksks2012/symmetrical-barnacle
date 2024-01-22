#include "include.h"

// Time Complexity: O(logn)
// Space Complexity: O(1)
class Solution {
public:

    // [left, right]
    int lower_bound(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    // [left, right)
    int lower_bound2(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    // (left, right)
    int lower_bound3(vector<int>& nums, int target) {
        int n = nums.size();
        int left = -1;
        int right = n - 1;
        while(left + 1 < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] < target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return right;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int start = lower_bound(nums, target);
        if(start == nums.size() || nums[start] != target) { 
            return vector<int> {-1, -1};
        }

        int end = lower_bound(nums, target + 1) - 1;
        
        return vector<int> {start, end}; 
    }
};