#include "include.h"

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long pre = 0, suf = accumulate(nums.begin(), nums.end(), 0LL);
        int ans = 0;

        for(int i = 0; i < n - 1; i++) {
            pre += nums[i];
            suf -= nums[i];
            if(pre >= suf) {
                ans++;
            }
        }

        return ans;
    }
};