#include "include.h"

class Solution {
public:
    void back_tracking(vector<vector<int>>& res, vector<int>& nums, int cur) {
        if (cur == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = cur; i < nums.size(); i++) {
            swap(nums[i], nums[cur]);
            back_tracking(res, nums, cur + 1);
            swap(nums[cur], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;

        if (nums.empty()) return res;
        back_tracking(res, nums, 0);

        return res;
    }

};