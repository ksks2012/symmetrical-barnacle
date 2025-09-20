#include "include.h"

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j] && (i * j) % k == 0) {
                    res++;
                }
            }
        }
        return res;
    }
};

// Vlad
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, vector<int>> m;
        for (int i = 0;  i < nums.size(); ++i)
            m[nums[i]].push_back(i);

        for (auto &[n, ids] : m) {
            unordered_map<int, int> gcds;
            for (auto i : ids) {
                auto gcd_i = gcd(i, k);
                for (auto &[gcd_j, cnt] : gcds)
                    res += gcd_i * gcd_j % k ? 0 : cnt;
                ++gcds[gcd_i];
            }
        }
        return res;
    }
};