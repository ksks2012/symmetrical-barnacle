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

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int res = 0;
        int sum1 = 0, sum2 = 0;
        int left1 = 0, left2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum1 += nums[i];
            // >= goal
            while (left1 <= i && sum1 >= goal) {
                sum1 -= nums[left1];
                left1++;
            }
            res += left1; 

            sum2 += nums[i];
            // > goal
            while (sum2 > goal) {
                sum2 -= nums[left2];
                left2++;
            }
            res -= left2;
        }

        return res;
    }
};

class Solution {
public:
    int helper(vector<int>& nums, int goal) {
        int res = 0;
        int sum = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while (left <= right && sum > goal) {
                sum -= nums[left];
                left++;
            }
            res += (right - left + 1);
        }
        return res;
    }   

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums, goal) - helper(nums, goal - 1);
    }
};

