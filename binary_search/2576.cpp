#include "include.h"

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        auto helper = [&](int k) -> bool {
            for (int i = 0; i < k; i++) {
                if (nums[i] * 2 > nums[nums.size() - k + i]) {
                    return false;
                }
            }
            return true;
        };

        int left = 0, right = nums.size() / 2 + 1;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            (helper(mid) ? left : right) = mid;
        }
        return left * 2;
    }
};