#include "include.h"

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++) {
            // count good pair
            res += (long long)i - m[nums[i] - i];
            m[nums[i] - i]++;
        }

        return res;
    }
};