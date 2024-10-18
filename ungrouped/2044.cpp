#include "include.h"

class Solution {
public:
    void backtrack(const vector<int> &nums, int index, int cur_or, int maxi_or, int &res) {
        if (cur_or == maxi_or) {
            res++;
        }

        for (int i = index; i < nums.size(); ++i) {
            backtrack(nums, i + 1, cur_or | nums[i], maxi_or, res);
        }
    }

    int countMaxOrSubsets(vector<int> &nums) {
        int maxi_or = 0;

        // Step 1: Compute the maximum OR
        for (int num : nums) {
            maxi_or |= num;
        }

        int res = 0;
        // Step 2: Backtrack to count the subsets
        backtrack(nums, 0, 0, maxi_or, res);

        return res;
    }
};