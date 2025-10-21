#include "include.h"

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 1;
        int mini = nums[0];
        for(int i = 1; i < n; i++) {
            if(nums[i] - mini > k) {
                res++;
                mini = nums[i];
            }
        }
        return res;
    }
};