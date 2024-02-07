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