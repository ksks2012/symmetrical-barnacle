#include "include.h"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // left: next 0
        // mid: current
        // right: next 2
        int left = 0, mid = 0, right = nums.size() - 1;
        while(mid <= right) {
            if(nums[mid] == 0) {
                swap(nums[mid], nums[left]);
                mid++;
                left++;
            } else if(nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[right]);
                right--;
            }
        }
    }
};