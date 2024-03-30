#include "include.h"

class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0;

        if(nums[0] != 0) {
            res = 1;
        }

        for(int i = 0; i < n; i++) {
            if(nums[i] < i + 1) {
                if(i + 1 < n && i + 1 < nums[i + 1]) {
                    res++;
                } else if(i + 1 == n) {
                    res++;
                }
            }
        }

        return res;
    }
};