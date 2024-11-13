#include "include.h"

class Solution {
public:
    long long two_pointer(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        long long res = 0;
        while(left < right) {
            while(left < right && nums[left] + nums[right] > target) {
                right--;
            }
            res += right - left;
            left++;
        }
        return res;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());

        return two_pointer(nums, upper) - two_pointer(nums, lower - 1);
    }
};

// Binary search
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(begin(nums), end(nums));
        long long ans = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            int low = lower_bound(begin(nums) + i + 1, end(nums),lower - nums[i]) - begin(nums);
            int high = upper_bound(begin(nums) + i + 1, end(nums),upper - nums[i]) - begin(nums);
            ans += 1LL * (high - low);
        }
        return ans;
    }
};