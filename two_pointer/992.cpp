#include "../include.h"

// lee
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

    int atMostK(vector<int>& nums, int k) {
        int left = 0, res = 0;
        unordered_map<int, int> count;
        for (int right = 0; right < nums.size(); ++right) {
            count[nums[right]]++;
            if (count[nums[right]] == 1) {
                k--;
            }
            while (k < 0) {
                count[nums[left]]--;
                if (!count[nums[left]]) {
                    k++;
                }
                left++;
            }
            res += right - left + 1;
        }
        return res;
    }
};