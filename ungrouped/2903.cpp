#include "../include.h"

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        vector<int> res(2, -1);

        for(int i = 0; i < n; ++i) {
            for(int j = i + indexDifference; j < n; ++j) {
                if(abs(nums[i] - nums[j]) >= valueDifference) {
                    res[0] = i;
                    res[1] = j;
                    return res;
                }
            }
        }

        return res;
    }
};