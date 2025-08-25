#include "include.h"

class Solution {
public:
    int countElements(vector<int>& nums) {
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        int res = 0;
        for (int num : nums) {
            if (num > mini && num < maxi) {
                res++;
            }
        }
        return res;
    }
};