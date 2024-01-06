#include "include.h"

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int cur = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            cur ^= nums[i];
        }
        std::bitset<32> tmp(cur);
        std::bitset<32> k_tmp(tmp); 

        int ans = 0;
        for(int i = 0; i < 32; i++) {
            if(tmp[i] != k_tmp[i]) {
                ans++;
            }
        }

        return ans;
    }
};