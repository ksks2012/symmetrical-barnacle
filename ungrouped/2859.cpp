#include "include.h"

class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(__builtin_popcount(i) == k)
                res += nums[i];
        }
        return res;
    }
};

// hacked by Vlad
class Solution {
public:
    int getNextSamePopcount(int a) {
        if (a == 0)
            return INT_MAX;
        int c = (a & -a), r = a + c;
        return ((((r ^ a) >> 2) / c) | r);
    }    
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int res = 0;
        for (int i = (1 << k) - 1; i < nums.size(); i = getNextSamePopcount(i))
            res += nums[i];
        return res;
    }
};