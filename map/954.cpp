#include "../include.h"

class Solution {
public:
    bool canReorderDoubled(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto i : nums) 
            mp[i]++;
        sort(nums.begin(), nums.end(), [](int a, int b){ return abs(a)<abs(b); });
        for(auto idx : nums){
            if(mp[idx] == 0) 
                continue;

            if(mp[2 * idx] == 0) 
                return false;
            mp[idx]--; 
            mp[2 * idx]--;
        }
        return true;
    }
};