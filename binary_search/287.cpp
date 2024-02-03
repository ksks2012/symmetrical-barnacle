#include "include.h"

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 1;
        int right = n - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            for(int i = 0; i < n; i++) {
                if(nums[i] <= mid) {
                    count++;
                }
            }
            if(count <= mid) {
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
    int findDuplicate(vector<int>& nums) {
        if (nums.size() > 1) {
            int slow = nums[0];
            int fast = nums[nums[0]];
            while (slow != fast) {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }

            fast = 0;
            while (fast != slow) {
                fast = nums[fast];
                slow = nums[slow];
            }
            return slow;
        }
        return -1;
    }
};