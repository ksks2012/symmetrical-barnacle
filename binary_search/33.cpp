#include "include.h"

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};

// endlesscheng
class Solution {
    int findMin(vector<int> &nums) {
        int left = -1, right = nums.size() - 1; // (-1, n-1)
        while (left + 1 < right) { // not null
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums.back()) right = mid; // blue
            else left = mid; // red
        }
        return right;
    }

    int lower_bound(vector<int> &nums, int left, int right, int target) {
        while (left + 1 < right) { // not null
            // nums[left] < target
            // nums[right] >= target
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid; // range -> (mid, right)
            else
                right = mid; // range -> (left, mid)
        }
        return nums[right] == target ? right : -1;
    }

public:
    int search(vector<int> &nums, int target) {
        int i = findMin(nums), left, right;
        if (target > nums.back()) left = -1, right = i; // left part
        else left = i - 1, right = nums.size(); // right part
        return lower_bound(nums, left, right, target);
    }
};