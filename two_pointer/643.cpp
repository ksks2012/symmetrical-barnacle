#include "include.h"

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int res = INT_MIN;
        int tmp = 0;
        for(int right = 0; right < nums.size(); right++) {
            tmp += nums[right];
            if(right < k - 1) {
                continue;
            }
            res = max(res, tmp);
            tmp -= nums[right - k + 1];
        }
        return (double)res / k;
    }
};