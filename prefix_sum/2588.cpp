#include "include.h"

// lee
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int, int> dp{{0, 1}};
        long long res = 0, pre = 0;
        for (int a : nums)
            res += dp[pre ^= a]++;
        return res;
    }
};