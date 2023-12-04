#include "include.h"

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i < n + 1; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;

        int a = 1;
        int b = 1;
        for(int i = 2; i < n + 1; i++) {
            int tmp = b;
            b = a + b;
            a = tmp;
        }
        return b;
    }
};

class Solution {
public:
    int climbStairs(int n) {
        if(n < 0)
            return 1;
        if(n <= 2)
            return n;

        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

class Solution {
public:
    int DFS(int n, vector<int> &memo) {
        if(n < 0)
            return 1;
        if(n <= 2)
            return n;
        if(memo[n] != -1)
            return memo[n];

        memo[n] = DFS(n - 1, memo) + DFS(n - 2, memo);
        return memo[n];
    }

    int climbStairs(int n) {
        vector<int> memo(n + 1, -1);
        return DFS(n, memo);
    }
};
