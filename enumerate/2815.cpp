#include "include.h"

class Solution {
public:
    int maxSum(vector<int>& nums) {
        int res = -1, maxi[10] = {};
        for (auto num : nums) {
            int max_d = 0;
            for (int v = num; v; v /= 10)
                max_d = max(max_d, v % 10);

            if (maxi[max_d])
                res = max(res, maxi[max_d] + num);

            maxi[max_d] = max(maxi[max_d], num);
        }
        return res;
    }
};
    