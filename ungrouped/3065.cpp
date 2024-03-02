#include "include.h"

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int ans = 0;

        ans = lower_bound(nums.begin(), nums.end(), k) - nums.begin();

        return ans;      
    }
};