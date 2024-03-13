#include "include.h"

class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        // if no moves, return top of list
        if(k == 0) {
            return n >= 1 ? nums[0] : -1;
        }
        // if only one move is allowed, we can only remove the topmost element
        if(k == 1) {
            return n == 1 ? -1 : nums[1];
        }
        // 
        if(n == 1) {
            return k % 2 == 0 ? nums[0] : -1;
        }

        int res = *max_element(nums.begin(), nums.begin() + min(k - 1, n));
        if (k < n) 
            res = max(res, nums[k]);
        return res;
    }
};

// votrubac
class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if (nums.size() == 1 && k % 2)
            return -1;
        if (k < 2)
            return nums[k];
        if (k >= nums.size())
            return *max_element(begin(nums), end(nums) - (k == nums.size()));
        return max(nums[k], *max_element(begin(nums), begin(nums) + k - 1));
    }
};