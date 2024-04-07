#include "include.h"

class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); 
        long long res = 0; 

        int n = nums.size(); 

        for (int i = 0; i < n; i++) { 
            if (i < n / 2) {
                res += max(0, nums[i] - k); 
            } else if (i == n / 2) {
                res += abs(k - nums[i]); 
            } else {
                res += max(0, k - nums[i]); 
            }
        } 
        return res; 
    }
};