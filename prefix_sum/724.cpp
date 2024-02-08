#include "include.h"

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n + 1, 0);
        int tmp = 0;

        for(int i = 0; i < n; i++) {
            tmp += nums[i];
            sum[i + 1] = tmp;
        }
        
        for(int i = 0; i < n; i++) {
            if(sum[n] - sum[i + 1] == sum[i] - sum[0]) {
                return i;
            }
        }

        return -1;
    }
};