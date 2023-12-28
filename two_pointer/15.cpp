#include "../include.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans; 
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = n - 1;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum > 0)
                    right--;
                else if(sum < 0)
                    left++;
                else {
                    ans.push_back({nums[left], nums[right], nums[i]});
                    right--;
                    while(right > left && nums[right] == nums[right + 1]) {
                        right--;
                    }
                    left++;
                    while(right > left && nums[left] == nums[left - 1]) {
                        left++;
                    }
                }
            }   
        }
        return ans;
    }
};

// Optimization
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans; 
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            // op1
            if(nums[i] + nums[i + 1] + nums[i + 2] > 0)
                break;
            // op2
            if(nums[i] + nums[n - 1] + nums[n - 2] < 0)
                continue;

            int left = i + 1;
            int right = n - 1;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum > 0)
                    right--;
                else if(sum < 0)
                    left++;
                else {
                    ans.push_back({nums[left], nums[right], nums[i]});
                    right--;
                    while(right > left && nums[right] == nums[right + 1]) {
                        right--;
                    }
                    left++;
                    while(right > left && nums[left] == nums[left - 1]) {
                        left++;
                    }
                }
            }   
        }
        return ans;
    }
};