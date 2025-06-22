#include "../include.h"

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
  
        int n = nums.size();
        vector<int> res(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[i]) {
                    res[i]++;
                } else if (nums[j] > nums[i]) {
                    res[j]++;
                }
            }
        }

        return res;
    }
};