#include "include.h"

class Solution {
public:
    void back_tracking(vector<vector<int>>& res, vector<int>& nums, int cur, vector<int> out) {
        res.push_back(out);
        if(cur == nums.size()) {
            return;
        }

        for(int i = cur; i < nums.size(); i++) {
            if(i > cur && nums[i] == nums[i -1]) {
                continue;
            }
            out.push_back(nums[i]);
            back_tracking(res, nums, i + 1, out);
            out.pop_back();
        }
	}

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        back_tracking(ans, nums, 0, vector<int>());
        return ans;
    }
};