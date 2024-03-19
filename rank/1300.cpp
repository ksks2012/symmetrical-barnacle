#include "include.h"

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int res = 0;
        int i = 0;
        for(; i < n; i++) {
            if(target <= arr[i] * (n - i)) {
                break;
            }
            target -= arr[i];
        }

        if(i == n) {
            return arr[n - 1];
        }

        return int(round((target - 0.0001) / (n - i)));
    }
};