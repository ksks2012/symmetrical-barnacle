#include "../include.h"

class Solution {
public:
    int mod = 1e9 + 7;
    int countNicePairs(vector<int>& nums) {
        unordered_map<long long, int> count;
        long long res = 0;
        // nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
        // nums[i] - rev(nums[i]) = nums[j] - rev(nums[j])
        for (int i = 0; i < nums.size(); i++) {
            long long key = (long long)nums[i] - rev(nums[i]);
            res = (res + count[key]) % mod;
            count[key]++;
        }
        return res;
    }

    int rev(int x) {
        int res = 0;
        while (x > 0) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};