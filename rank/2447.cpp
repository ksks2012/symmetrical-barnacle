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
                // clear repeating GCD
                for (auto [prev_gcd, cnt] : gcds)
                    gcds1[gcd(prev_gcd, nums[i])] += cnt;
            }
            res += gcds1[k];
            swap(gcds, gcds1);
        }
        return res;
    }
};

class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int res = 0;
        vector<pair<int,int>> tmp({{-1, 0}});

        for(int i = 0; i < nums.size(); ++i) {
            for(int j = 1; j < tmp.size(); ++j)
                tmp[j].second = gcd(tmp[j].second, nums[i]);
            tmp.push_back({i, nums[i]});

            for(int j = (int)tmp.size() - 2; j >= 1; --j)
                if(tmp[j].second == tmp[j + 1].second)
                    tmp[j].first = tmp[j + 1].first;
            tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

            for(int j = 1; j < tmp.size(); ++j)
                if(tmp[j].second == k)
                    res += tmp[j].first - tmp[j - 1].first;
        }

        return res;
    }
};