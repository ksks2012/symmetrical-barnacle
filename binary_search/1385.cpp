#include "include.h"

class Solution {
public:
    int lower_bound(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    int upper_bound(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        
        sort(arr2.begin(), arr2.end());
        int ans = 0;
        for (int a : arr1) {
            auto it1 = lower_bound(arr2, a - d);
            auto it2 = upper_bound(arr2, a + d);
            if (it1 == it2) 
                ++ans;
        }
        return ans;
    }
};

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        
        sort(arr2.begin(), arr2.end());
        int ans = 0;
        for (int a : arr1) {
            auto it1 = lower_bound(begin(arr2), end(arr2), a - d);
            auto it2 = upper_bound(begin(arr2), end(arr2), a + d);
            if (it1 == it2) 
                ++ans;
        }
        return ans;
    }
};