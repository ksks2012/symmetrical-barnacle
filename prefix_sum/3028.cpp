#include "include.h"

class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int n = nums.size();
        int tmp = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            tmp += nums[i];
            if(tmp == 0)
                ans++;
        }

        return ans;
    }
};