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

// TLE
class Solution {
public:
    int DFS(vector<int>& cost, int cur) {
        if(cur < 0)
            return 0;
        
        return cost[cur] + min(DFS(cost, cur - 1), DFS(cost, cur - 2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        return min(DFS(cost, n - 1), DFS(cost, n - 2));
    }
};

class Solution {
public:
    int DFS(vector<int>& cost, vector<int>& memo, int cur) {
        if(cur < 0)
            return 0;
        if(memo[cur] != -1)
            return memo[cur];

        memo[cur] = cost[cur] + min(DFS(cost, memo, cur - 1), DFS(cost, memo, cur - 2));
        
        return memo[cur];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n + 1, -1);
        
        return min(DFS(cost, memo, n - 1), DFS(cost, memo, n - 2));
    }
};
