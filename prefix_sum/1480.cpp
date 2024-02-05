#include "include.h"

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n, 0);
        int tmp = 0;

        for(int i = 0; i < n; i++) {
            tmp += nums[i];
            sum[i] = tmp;
        }

        return sum;
    }
};