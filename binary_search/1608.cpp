#include "../include.h"

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // O(NlogN)
        const int n = nums.size();
        if (nums[0] >= n) 
            return n;
            
        int left = 1, right = n - 1;
        while (left <= right) { // O(LogN) * O(1)
            int m = left + (right - left) / 2;
            if (nums[m] >= (n - m) && nums[m - 1] < (n - m)) 
                return (n - m);
            else if (nums[m] >= (n - m)) 
                right = m - 1;
            else 
                left = m + 1;
        }
        return -1;
    }
};