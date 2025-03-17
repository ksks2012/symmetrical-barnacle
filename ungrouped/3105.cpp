#include "include.h"

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int incr = 0, decr = 0;

        for(; right < nums.size(); right++) {
            if(right > 0 && nums[right] <= nums[right - 1]) {
                left = right;
            }
            incr = max(incr, right - left + 1);
        }

        left = 0;
        for(right = 0; right < nums.size(); right++) {
            if(right > 0 && nums[right] >= nums[right - 1]) {
                left = right;
            }
            decr = max(decr, right - left + 1);
        }

        return max(incr, decr);      
    }
};


class Solution {
public:
    int longestMonotonicSubarray(vector<int> &nums) {
        int res = 1;
        int i = 0, n = nums.size();
        while (i < n - 1) {
            if (nums[i + 1] == nums[i]) {
                i++; // skip
                continue;
            }
            int start = i;
            bool inc = nums[i + 1] > nums[i]; // increase or decrease
            i += 2;
            while (i < n && nums[i] != nums[i - 1] && (nums[i] > nums[i - 1]) == inc) {
                i++;
            }
            res = max(res, i - start);
            i--;
        }
        return res;
    }
};