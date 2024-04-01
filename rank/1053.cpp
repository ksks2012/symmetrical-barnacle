#include "../include.h"

class Solution {
public:
    vector<int> prevPermOpt1(vector<int> &arr) {
        int idx = 0;

        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] > arr[i + 1])
                idx = i;
        }
        
        int maxi = 0;
        int max_idx = 0;
        for (int i = idx + 1; i < arr.size(); i++) {
            if (arr[i] < arr[idx]) {
                if (maxi != arr[i]) {
                    max_idx = i;
                    maxi = arr[i];
                }
            }
        }
        swap(arr[idx], arr[max_idx]);
        return arr;
    }
};