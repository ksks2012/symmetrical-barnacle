#include "include.h"

class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);

        long long tmp = 0;
        int maxi = 0;
        for(int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            tmp += nums[i] + maxi;
            ans[i] = tmp;
        }

        return ans;
    }
};