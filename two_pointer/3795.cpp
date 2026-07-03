#include "include.h"

class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int left = 0;
        int mini = INT_MAX;
        int tmp = 0;
        for(int right = 0; right < n; right++) {
            mp[nums[right]]++;
            if(mp[nums[right]] == 1) {
                tmp += nums[right];
            }
            while(tmp > k) {
                mini = min(mini, right - left + 1);
                mp[nums[left]]--;
                if(mp[nums[left]] == 0) {
                    tmp -= nums[left];
                }
                left++;
            }
        }

        return mini == INT_MAX ? -1 : mini;
    }
};