#include "include.h"

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;
        int left = 0;
        int max_len = 0;

        for (int right = 0; right < n; ++right) {
            m[nums[right]]++;

            while (m[nums[right]] > k) {
                m[nums[left]]--;
                left++;
            }

            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};