#include "include.h"

class Solution {
public:
    int maxWidthRamp(vector<int>& nums, int res = 0) {
        vector<pair<int, int>> tmp;
        for (auto i = 0; i < nums.size(); ++i) {
            if (tmp.empty() || tmp.back().first > nums[i]) 
                tmp.push_back({ nums[i], i });
            else 
                res = max(res, i - lower_bound(tmp.begin(), tmp.end(), make_pair(nums[i], INT_MAX), greater<pair<int, int>>())->second);
        }
        return res;
    }
};

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> s;
        int res = 0, n = nums.size();
        for (int i = 0; i < n; ++i)
            if (s.empty() || nums[s.top()] > nums[i])
                s.push(i);
        for (int i = n - 1; i > res; --i)
            while (!s.empty() && nums[s.top()] <= nums[i])
                res = max(res, i - s.top()), s.pop();
        return res;
    }
};