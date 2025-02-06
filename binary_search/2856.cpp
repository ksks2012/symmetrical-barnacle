#include "include.h"

class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size();
        int x = nums[n / 2];
        int maxi = ranges::upper_bound(nums, x) - ranges::lower_bound(nums, x);
        return max(maxi * 2 - n, n % 2);
    }
};

class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp(n, 0);

        int m = n - 1;

        unordered_map<int, int> idx_map;

        for (int i = 0; i < n; i++) {
            if(idx_map.find(nums[i]) != idx_map.end()) {
                idx_map[nums[i]]++;
            } else {
                idx_map[nums[i]]++;
            }
        }

        int max_size_num = -1;
        for(auto it : idx_map){
            max_size_num = max(max_size_num, it.second);
        }

        if (max_size_num <= n / 2) {
            return n % 2;
        }
        
        return 2 * max_size_num - n;
    }
};

class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp(n, 0);

        int m = n - 1;

        unordered_map<int, int> idx_map;
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            idx_map[nums[i]]++;
            maxi = max(maxi, idx_map[nums[i]]);
        }
        
        return max(maxi * 2 - n, n % 2);
    }
};