#include "include.h"

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        for (int n: nums)
            if (n == res % 2)
                res++;
        return res;
    }
};