#include "include.h"

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int res = 0;

        unordered_set<int> numSet(nums.begin(), nums.end());
        for (int num : nums) {
            if (numSet.count(num + diff) && numSet.count(num + 2 * diff)) {
                res++;
            }
        }

        return res;
    }
};