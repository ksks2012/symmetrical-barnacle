#include "include.h"

class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n < 2)
            return n;

        vector<int> dp(n + 1, 0);
        int ans = 0;

        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i < n + 1; i++) {
            if(i % 2 == 0) {
                dp[i] = dp[i / 2];
            } else {
                int idx = i / 2;
                dp[i] = dp[idx] + dp[idx + 1];
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};