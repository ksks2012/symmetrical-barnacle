#include "include.h"

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target)
                ans.push_back(i);
        }
        
        return ans;
    }
};

class Solution {
public:
    int lower_bound(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int pos = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(target == nums[mid]) {
                pos = mid;
                right = mid - 1;
            }
            else if(target < nums[mid])
                right = mid - 1;
            else 
                left = mid + 1;
        }
        return pos;
    }

    int upper_bound(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int pos = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(target == nums[mid]) {
                pos = mid;
                left = mid + 1;
            }
            else if(target < nums[mid])
                right = mid - 1;
            else 
                left = mid + 1;
        }
        return pos;
    }

    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> ans;

        int lower = lower_bound(nums, target);
        int upper = upper_bound(nums, target);

        if(lower == -1 || upper == -1)
            return ans;

        for(int i = lower; i <= upper; i++) {
            ans.push_back(i);
        }
        
        return ans;
    }
};