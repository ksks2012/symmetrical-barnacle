#include "include.h"

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int res = 0, sum = 0;
        for(auto n : nums) {
            sum += n;
            res = min(res, sum);
        }

        return -res + 1;
    }
};