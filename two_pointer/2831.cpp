#include "include.h"

class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int n = nums.size();

        int maxi = 0;
        int left = 0;
        for(int right = 0; right < n; ++right) {
            maxi = max(maxi, ++m[nums[right]]);
            if(right - left + 1 - maxi > k) {
                --m[nums[left++]];
            }
        }
        return maxi;
    }
};