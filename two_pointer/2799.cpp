#include "../include.h"

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> mp;
        int res = 0, left = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        int target = mp.size();
        mp.clear();

        for(int right = 0; right < n; right++) {
            mp[nums[right]]++;
            while(mp.size() == target) {
                mp[nums[left]]--;
                if(mp[nums[left]] == 0) {
                    mp.erase(nums[left]);
                }
                left++;
            }
            res += left;
        }
        return res;

    }
};