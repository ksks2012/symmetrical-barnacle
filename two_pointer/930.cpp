#include "../include.h"

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> c({{0, 1}});
        int cur = 0, res = 0;
        for (int i : nums) {
            cur += i;
            res += c[cur - goal];
            c[cur]++;
        }
        return res;
    }
};

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int res = 0, sum = 0, left = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            while (left < i && sum > goal) {
                sum -= nums[left];
                left++;
            }
                
            if (sum < goal) 
                continue;
            if (sum == goal) 
                ++res;
            for (int j = left; j < i && nums[j] == 0; ++j) {
                ++res;
            }
        }
        return res;
    }
};
