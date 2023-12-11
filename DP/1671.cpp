#include "include.h"

class Solution {
public:
    // Problem 300.
    vector<int> index_LIS(vector<int> nums) {
        int n = nums.size();
        vector<int> lens(n, 0);

        auto end = nums.begin();
        for(int i = 0; i < n; i++) {
            auto it = lower_bound(nums.begin(), end, nums[i]);
            lens[i] = (it - nums.begin() + 1);
            *it = nums[i];
            if(it == end)
                ++end;
        }
        return lens;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        vector<int> LIS_vec = index_LIS(nums);
        reverse(nums.begin(), nums.end());
        vector<int> LDS_vec = index_LIS(nums);
        reverse(LDS_vec.begin(), LDS_vec.end());

        int max_sum = 0;
        for(int i = 0; i < n; i++) {
            // length 2 for mountain
            if(LIS_vec[i] >= 2 && LDS_vec[i] >= 2)
                max_sum = max(LIS_vec[i] + LDS_vec[i], max_sum);
        }

        return n - max_sum + 1;
    }
};