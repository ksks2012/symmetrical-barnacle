#include "include.h"

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int res = 0;
        int tmp = 0;
        for(int right = 0; right < arr.size(); right++) {
            tmp += arr[right];
            if(right < k - 1) {
                continue;
            }
            if(right >= k) {
                tmp -= arr[right - k];
            }
            if(right >= k - 1 && tmp / k >= threshold) {
                res++;
            }
        }
        return res;
    }
};