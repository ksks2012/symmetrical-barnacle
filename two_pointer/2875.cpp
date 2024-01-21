#include "include.h"

class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n = nums.size();
        long long sum = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }

        int mini = INT_MAX;
        int tmp_target = target % sum;
        long long cur = 0;
        int left = 0;
        for(int right = 0; right < n * 2; right++) {
            cur += nums[right % n];
            while(cur > tmp_target) {
                cur -= nums[left++ % n];
            }
            if(cur == tmp_target) {
                mini = min(mini, right - left + 1);
            }
        }

        return mini == INT_MAX ? -1 : mini + target / sum * n;
    }
};