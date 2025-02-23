#include "../include.h"

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        
        int left = 0, right = nums.size() - 1;

        while(left <= right) {
            int left_sq = nums[left] * nums[left];
            int right_sq = nums[right] * nums[right];

            if(left_sq > right_sq) {
                res[right - left] = left_sq;
                left++;
            } else {
                res[right - left] = right_sq;
                right--;
            }
        }


        return res;
    }
};