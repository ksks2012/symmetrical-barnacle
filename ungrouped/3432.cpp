#include "../include.h"

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int res = 0;

        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        int cur = nums[0];
        for(int i = 1; i < n; i++) {
            if((cur - (sum - cur)) % 2 == 0) {
                res++;
            }
            cur += nums[i];
        }

        return res;
    }
};