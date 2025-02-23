#include "../include.h"

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(begin(arr), end(arr));
        int left = 0, right = arr.size() - 1;
        int med = arr[(arr.size() - 1) / 2];
        while (--k >= 0)
            if (med - arr[left] > arr[right] - med)
                ++left;  
            else
                --right;
        arr.erase(begin(arr) + left, begin(arr) + right + 1);
        return arr;
    }
};