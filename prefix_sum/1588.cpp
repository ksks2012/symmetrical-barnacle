#include "include.h"

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> sum(n + 1, 0);
        int tmp = 0;
        for(int i = 0; i < n; i++) {
            tmp += arr[i];
            sum[i + 1] = tmp;
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 1; j + i <= n; j += 2) {
                ans += (sum[i + j] - sum[i]);
            }
        }
            
        return ans;     
    }
};