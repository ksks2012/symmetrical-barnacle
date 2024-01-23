#include "include.h"

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        
        // [0, n - 2]
        // (-1, n - 1)
        int left = -1;
        int right = n - 1;

        while(left + 1 < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] < nums[n - 1]) {
                right = mid;
            } else {
                left = mid;
            }
        }

        return nums[right];
    }
};