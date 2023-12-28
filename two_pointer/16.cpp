#include "../include.h"

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int min_diff = INT_MAX;
        int ans = 0;
        int n = nums.size();

        for(int i = 0; i < n - 2; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = n - 1;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int diff = target - sum;
                if(diff == 0) {
                    return target;
                }

                if(sum > target) {
                    if(sum - target < min_diff) {
                        min_diff = sum - target;
                        ans = sum;
                    }
                    right--;
                } else {
                    if(target - sum < min_diff) {
                        min_diff = target - sum;
                        ans = sum;
                    }
                    left++;
                }
            }   
        }
        return ans;
    }
};

// Optimization
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int min_diff = INT_MAX;
        int ans = 0;
        int n = nums.size();

        for(int i = 0; i < n - 2; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // op1
            int sum = nums[i] + nums[i + 1] + nums[i + 2];
            if(sum > target) {
                if(sum - target < min_diff) {
                    ans = sum;
                }
                break;
            }

            // op2
            sum = nums[i] + nums[n - 1] + nums[n - 2];
            if(sum < target) {
                if(target - sum < min_diff) {
                    min_diff = target - sum;
                    ans = sum;
                }
                continue;
            }

            int left = i + 1;
            int right = n - 1;
            while(left < right) {
                sum = nums[i] + nums[left] + nums[right];
                int diff = target - sum;
                if(diff == 0) {
                    return target;
                }

                if(sum > target) {
                    if(sum - target < min_diff) {
                        min_diff = sum - target;
                        ans = sum;
                    }
                    right--;
                } else {
                    if(target - sum < min_diff) {
                        min_diff = target - sum;
                        ans = sum;
                    }
                    left++;
                }
            }   
        }
        return ans;
    }
};