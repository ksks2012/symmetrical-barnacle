#include "include.h"

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        for (auto& [_, v] : mp) {
            int tmp = v[0];
            v.insert(v.begin(), v.back() - n);
            v.push_back(tmp + n);
        }

        vector<int> res;
        for (int q : queries) {
            auto& v = mp[nums[q]];
            if(v.size() == 3) {
                res.push_back(-1);
            } else {
                int left = lower_bound(v.begin(), v.end(), q) - v.begin();
                res.push_back(min(q - v[left - 1], v[left + 1] - q));
            }
        }
        return res;
    }
};