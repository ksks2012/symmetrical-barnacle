#include "../include.h"

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int count = 1;
        int i = 0;
        while(k > 0) {
            if(i >= arr.size()) {
                k--;
            } else if(arr[i] != count) {
                k--;
            } else {
                i++;
            }
            if(k == 0) {
                return count;
            }
            count++;
        }
        return -1;
    }
};

// lee
class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int left = 0, right = nums.size(), m;
        while (left < right) {
            m = (left + right) / 2;
            if (nums[m] - 1 - m < k)
                left = m + 1;
            else
                right = m;
        }
        return left + k;
    }
};