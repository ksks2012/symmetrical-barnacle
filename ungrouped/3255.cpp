#include "../include.h"

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        for (int i = 0, len = 1; i < n; i++) {
            if (i && nums[i] == nums[i - 1] + 1)
                ++len;
            else
                len = 1;
            if (i + 1 >= k)
                res.push_back(len >= k ? nums[i] : -1);
        }
        return res;
    }
};