#include "include.h"

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for(int i = 1; i < n + 1; i++) {
            int cur = 0, best = 0;
            for(int j = 1; j <= k && i - j >= 0; j++) {
                cur = max(cur, arr[i - j]);
                best = max(best, dp[i - j] + cur * j);
            }
            dp[i] = best;
        }

        return dp[n];        
    }
};