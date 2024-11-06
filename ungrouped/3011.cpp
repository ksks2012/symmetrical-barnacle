#include "include.h"

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> bit(n, 0);
        for(int i = 0; i < n; i++) {
            bitset<32> tmp(nums[i]);
            bit[i] = tmp.count();
        }

        vector<int> nums_sorted = nums;
        sort(nums_sorted.begin(), nums_sorted.end());
        vector<int> bit_sorted(n, 0);
        for(int i = 0; i < n; i++) {
            bitset<32> tmp(nums_sorted[i]);
            bit_sorted[i] = tmp.count();
        }

        for(int i = 0; i < n; i++) {
            int idx = find(nums.begin(), nums.end(), nums_sorted[i]) - nums.begin();
            int cur = i;
            if(idx == cur)
                continue; 
            if(idx > cur) {
                swap(idx, cur);
            }
            for(int j = idx; j <= cur; j++) {
                if(bit_sorted[i] != bit[j]) {
                    return false;
                }
            }
        }
        return true;
    }
};

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<pair<int,int>> mp;
        mp.push_back({nums[0], nums[0]});
        for(int i = 1; i < nums.size(); i++) {
            int cur = __builtin_popcount(nums[i]);
            int prev = __builtin_popcount(nums[i-1]);
            if(cur != prev) {   
                mp.push_back({nums[i], nums[i]});
            }
            mp.back().first = min(mp.back().first, nums[i]);
            mp.back().second = max(mp.back().second, nums[i]);
        }
        for(int i = 1; i < mp.size(); i++) {
            if(mp[i - 1].second > mp[i].first)
                return false;
        }
        return true;
    }
};