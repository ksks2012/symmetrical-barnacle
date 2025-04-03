#include "include.h"

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int ans = 0;

        set<int> tmp;

        for(int i = 0; i < nums.size(); i++) {
            for(int j = nums[i][0]; j <= nums[i][1]; j++) {
                tmp.insert(nums[i][j]);
            }
        }

        return tmp.size();
    }
};

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int max_end = ranges::max(nums, {}, [](const auto& a) { 
            return a[1]; 
        })[1];

        vector<int> diff(max_end + 2);
        for (auto& interval : nums) {
            diff[interval[0]]++;
            diff[interval[1] + 1]--;
        }

        int res = 0, s = 0;
        for (int d : diff) {
            s += d;
            res += s > 0;
        }
        return res;
    }
};