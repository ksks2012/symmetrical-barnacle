#include "../include.h"

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
  
        int n = nums.size();
        vector<int> res(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[i]) {
                    res[i]++;
                } else if (nums[j] > nums[i]) {
                    res[j]++;
                }
            }
        }

        return res;
    }
};

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
  
        int n = nums.size();
        vector<int> res(n, 0);

        vector<int> tmp(101, 0);
        for (int num : nums) {
            tmp[num]++;
        }
        for (int i = 1; i < 101; i++) {
            tmp[i] += tmp[i - 1];
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                res[i] = 0;
            } else {
                res[i] = tmp[nums[i] - 1];
            }
        }

        return res;
    }
};