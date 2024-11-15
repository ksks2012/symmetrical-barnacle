#include "include.h"

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size(), right = n - 1;
        for (; right > 0 && arr[right - 1] <= arr[right]; --right) ;
        auto res = right;
        for (int left = 0; left < right && (left == 0 || arr[left - 1] <= arr[left]); ++left) {
            while (right < n && arr[right] < arr[left])
                ++right;
            res = min(res, right - left - 1);
        }
        return res;
    }  
};