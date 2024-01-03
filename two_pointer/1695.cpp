#include "../include.h"

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int tmp[100001] = { 0 };
        int n = nums.size();

        int ans = 0;
        int cur = 0;
        int left = 0;
        for(int right = 0; right < n; right++) {
            cur += nums[right];
            tmp[nums[right]]++;
            while(tmp[nums[right]] > 1) {
                tmp[nums[left]]--;
                cur -= nums[left];
                left++;
            }
            ans = max(cur, ans);
        }

        return ans;
    }
};