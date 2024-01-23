#include "include.h"

// Time Complexity: O(logn)
// Space Complexity: O(1)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        // [0, n - 2]
        // (-1, n - 1)
        int left = -1;
        int right = n - 1;

        while(left + 1 < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid;
            }
        }

        return right;
    }
};