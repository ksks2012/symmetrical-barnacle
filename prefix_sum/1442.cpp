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

class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int n = nums.size(), ans = 0, prefix = 0;
        unordered_map<int, int> count = {{0, 1}}, total;
        for (int i = 0; i < n; ++i) {
            prefix ^= nums[i];
            ans += count[prefix]++ * i - total[prefix];
            total[prefix] += i + 1;
        }
        return ans;
    }
};

class Solution {
public:
    int countTriplets(vector<int>& nums) {
        nums.insert(nums.begin(), 0);
        int n = nums.size(), ans = 0;
        for (int i = 1; i < n; ++i)
            nums[i] ^= nums[i - 1];
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (nums[i] == nums[j])
                    ans += j - i - 1;
        return ans;
    }
};
