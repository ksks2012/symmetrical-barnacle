#include "include.h"

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0; 
        sort(nums.begin(), nums.end());
        for(int i = 2; i < n; i++) {
            int left = 0;
            int right = i - 1;
            while(left < right) {
                if(nums[left] + nums[right] > nums[i]) {
                    ans += right - left;
                    right--;
                } else {
                    left++;
                }
            }   
        }
        return ans;
    }
};