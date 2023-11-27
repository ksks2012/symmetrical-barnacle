#include "include.h"

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int m = cost.size();

        vector<int> dp(m + 1, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i < m + 1; i++) {
            int tmp = 0;
            if(i < m)
                tmp = cost[i];
            dp[i] = tmp + min(dp[i - 2], dp[i - 1]);
        }

        return dp[m];
    }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        for(int i = 2; i < n; i++) {
            cost[i] += min(cost[i - 1], cost[i - 2]);
        }
        return min(cost[n - 1], cost[n - 2]);
    }
};