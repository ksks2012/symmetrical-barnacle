#include "include.h"

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();

        bitset<32> cur(0);
        int ans = 0;
        int left = 0;
        for(int i = 0; i < n; i++) {
            bitset<32> tmp(nums[i]);
            while((cur & tmp) != 0) {
                cur &= bitset<32>(nums[left]).flip();
                left++;
            }
            cur |= tmp;
            ans = max(ans, i - left + 1);
        }

        return ans;
    }
};