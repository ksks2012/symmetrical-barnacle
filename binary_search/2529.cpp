#include "include.h"

class Solution {
public:
    int lower_bound(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(target == nums[mid]) {
                right = mid - 1;
            }
            else if(target < nums[mid])
                right = mid - 1;
            else 
                left = mid + 1;
        }
        return right;
    }

    int upper_bound(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(target == nums[mid]) {
                left = mid + 1;
            }
            else if(target < nums[mid])
                right = mid - 1;
            else 
                left = mid + 1;
        }
        return left;
    }

    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int lower = lower_bound(nums, 0);
        int upper = upper_bound(nums, 0);

        return max(lower + 1, n - upper);
    }
};

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        auto it_lower = lower_bound(nums.begin(), nums.end(), 0);
        auto it_upper = upper_bound(nums.begin(), nums.end(), 0);

        return max(it_lower - nums.begin(), nums.end() - it_upper);
    }
};

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0;
        int neg = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                pos++;
            } else if (nums[i] < 0) {
                neg++;
            }
        }
        return max(pos, neg);
    }
};
