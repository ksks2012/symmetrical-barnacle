#include "include.h"

// Time Complexity: O(n^3)
// Space Complexity: O(1)
class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        
        // Outer loop for the start index of the subarray
        for (int i = 0; i < n; i++) {
            // Inner loop for the end index of the subarray
            for (int j = i; j < n; j++) {
                bool ok = true; // Flag to check if subarray is increasing
                int lst = -1;   // Variable to keep track of the last element
                
                // Loop to check each element within or outside the subarray
                for (int k = 0; k < n; k++) {
                    if (k >= i && k <= j) {
                        // Elements within the subarray are skipped
                    } else {
                        ok &= (lst < nums[k]); // Check if the current element is greater than the last one
                        lst = nums[k];         // Update the last element
                    }
                }
                
                ans += ok; // Increment count if the subarray is "incremovable"
            }
        }
        return ans; // Return the total count of "incremovable" subarrays
    }
};

// Two Pointer + Binary Search
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        // left: increase
        for(; left < n - 1; left++) {
            if(nums[left + 1] <= nums[left]) 
                break;
        }
        // right: decrease
        int right = n - 1;
        for(; right > 0; right--) {
            if(nums[right - 1] >= nums[right]) 
                break;
        }

        int res = 0;
        while(left >= 0) {
            int upper = upper_bound(nums.begin() + right, nums.end(), nums[left]) - nums.begin();
            res += n - upper + 1;
            left--;
        }

        if(res < (n * (n + 1)) / 2) {
            res += n - right + 1;
        }
        return res;
    }
};
