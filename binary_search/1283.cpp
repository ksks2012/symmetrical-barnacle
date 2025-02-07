#include "include.h"

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = 1000000;

        while(left < right) {
            int mid = left + (right - left) / 2;
            int sum = 0;
            for(int i = 0; i < nums.size(); i++) {
                sum += (nums[i] + mid - 1) / mid;
            }
            if(sum > threshold) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
};

class Solution {
public:
    bool helper(vector<int>& nums, int threshold, int mid) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += (nums[i] + mid - 1) / mid;
            if(sum > threshold) {
                return false;
            }
        }
        return true;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 0;
        int right = 1000000;

        while(left + 1 < right) {
            int mid = left + (right - left) / 2;
            (helper(nums, threshold, mid) ? right : left) = mid;
        }

        return right;
    }
};