#include "../include.h"

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                if(i != j && target > nums[i] + nums[j])
                    count++;
            }
        }
        return count;
    }
};

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int count = 0;
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            if (nums[left] + nums[right] < target) {
                count += right - left;
                left++;
            } else {
                right--;
            }
        }
        return count;
    }
};