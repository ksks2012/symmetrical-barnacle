#include "../include.h"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        while(left < right) {
            int mid = left + (right - left) / 2;
            if(target == nums[mid]) {
                return mid;
            } else if(nums[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return nums[left] < target ? left + 1: left;
    }
};

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        if (target > nums[n - 1]) {
            return n;
        }

        while(left < right) {
            int mid = left + (right - left) / 2;
            if(target == nums[mid]) {
                return mid;
            } else if(nums[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return right;
    }
};

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n;

        if (target > nums[n - 1]) {
            return n;
        }

        while(left < right) {
            int mid = left + right >> 1;
            if(target == nums[mid]) {
                return mid;
            } else if(nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return right;
    }
};