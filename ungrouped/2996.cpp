#include "include.h"

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0] + 1;

        // sum of 1 ~ 50
        int tmp[1276] = { 0 };

        for(int i = 0; i < n; i++) {
            tmp[nums[i]]++;
        }

        int cur = nums[0];
        for(int i = 1; i < n; i++) {
            if(nums[i] != nums[i - 1] + 1) {
                break;
            }
            cur += nums[i];
        }

        int ans = cur;
        for(int i = cur; i < 1276; i++) {
            ans = i;
            if(tmp[i] == 0)
                return i;
        }
        return ans;
    }
};