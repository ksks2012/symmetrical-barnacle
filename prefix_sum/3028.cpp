#include "include.h"

class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int n = nums.size();
        int cur = 0;
        int res = 0;
        for(int i = 0; i < n; i++) {
            cur += nums[i];
            if(cur == 0)
                res++;
        }

        return res;
    }
};