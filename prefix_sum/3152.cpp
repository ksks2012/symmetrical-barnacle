#include "include.h"

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> tmp(nums.size());
        for (int i = 1; i < nums.size(); i++) {
            tmp[i] = tmp[i - 1] + (nums[i - 1] % 2 == nums[i] % 2);
        }
        vector<bool> res(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            auto& q = queries[i];
            res[i] = tmp[q[0]] == tmp[q[1]];
        }
        return res;
    }
};