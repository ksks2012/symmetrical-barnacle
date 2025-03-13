#include "../include.h"

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int res = 0;

        for(int i = 0; i < n - 1; i++) {
            int start = i;
            while(i + 1 < n && arr[i] < arr[i + 1]) {
                i++;
            }
            if(i == start) {
                continue;
            }
            int peak = i;
            while(i + 1 < n && arr[i] > arr[i + 1]) {
                i++;
            }
            if(i == peak) {
                continue;
            }
            res = max(res, i - start + 1);
            i--;
        }

        return res;
    }
};