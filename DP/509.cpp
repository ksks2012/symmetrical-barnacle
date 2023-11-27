#include "include.h"

class Solution {
public:
    int fib(int n) {
        if(n == 0)
            return 0;
        if(n == 1 || n == 2) 
            return 1;

        return fib(n - 1) + fib(n - 2);
    }
};

class Solution {
public:
    int fib(int n) {
        if(n == 0)
            return 0;
        if(n == 1 || n == 2) 
            return 1;

        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 1;

        for(int i = 2; i < n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

class Solution {
public:
    int fib(int n) {
        if(n < 2)
            return n;
        int a = 0, b = 1;
        for(int i = 1; i < n; i++){
            int tmp = b;
            b = a + b;
            a = tmp;
        }
        return b;
    }
};