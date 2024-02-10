#include "include.h"

// lee
// Time: O(n)
// Space: O(n)
class Solution {
public:
    int countTriplets(vector<int>& nums) {
        nums.insert(nums.begin(), 0);
        int n = nums.size();
        int ans = 0;
        for (int i = 1; i < n; ++i)
            nums[i] ^= nums[i - 1];

        unordered_map<int, int> count, total;
        for (int i = 0; i < n; ++i) {
            ans += count[nums[i]]++ * (i - 1) - total[nums[i]];
            total[nums[i]] += i;
        }
        return ans;
    }
};