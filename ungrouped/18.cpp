#include "../include.h"

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans; 
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 3; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for(int j = i + 1; j < n - 2; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int left = j + 1;
                int right = n - 1;
                while(left < right) {
                    long long sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum > target)
                        right--;
                    else if(sum < target)
                        left++;
                    else {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
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
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans; 
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 3; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for(int j = i + 1; j < n - 2; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                // op1
                if((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                    break;
                // op2
                if((long long)nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target)
                    continue;

                int left = j + 1;
                int right = n - 1;
                while(left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum > target)
                        right--;
                    else if(sum < target)
                        left++;
                    else {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
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
        }
        return ans;
    }
};