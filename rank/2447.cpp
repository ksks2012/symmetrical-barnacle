#include "include.h"

// Time Complexity: O(n^2)
class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i; j < n && nums[j] % k == 0; ++j) {
                nums[i] = gcd(nums[i], nums[j]);
                res += nums[i] == k;
            }
        return res;
    }
};

// Optimization
// Time Complexity: O(nlogm)
class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        unordered_map<int, int> gcds;
        for (int i = 0; i < n; ++i) {
            unordered_map<int, int> gcds1;
            if (nums[i] % k == 0) {
                ++gcds[nums[i]];
                for (auto [prev_gcd, cnt] : gcds)
                    gcds1[gcd(prev_gcd, nums[i])] += cnt;
            }
            res += gcds1[k];
            swap(gcds, gcds1);
        }
        return res;
    }
};