#include "include.h"

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int ans = 0, sum = 0;
        for(auto n : nums) {
            sum += n;
            ans = min(ans, sum);
        }

        return -ans + 1;
    }
};