#include "../include.h"

class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if (nums.size() <= 2) {
            return -1; // Not enough elements to have a non-min/max
        }

        int minVal = INT_MAX, maxVal = INT_MIN;
        for (int num : nums) {
            if (num < minVal) {
                minVal = num;
            }
            if (num > maxVal) {
                maxVal = num;
            }
        }
        int res = -1;
        for (int num : nums) {
            if (num != minVal && num != maxVal) {
                res = num; // Found a number that is neither min nor max
                break;
            }
        }

        return res;
    }
};