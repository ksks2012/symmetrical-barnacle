#include "include.h"

// TLE
class Solution {
public:
    int mod = 1e9 + 7;
    unordered_set<string> tmp;
    int DFS(int low, int high, int zero, int one, int cur) {
        if(cur > high)
            return 0;
        long long tmp = 0;
        if(cur >= low && cur <= high)
            tmp++;

        tmp += DFS(low, high, zero, one, cur + zero) % mod;
        tmp += DFS(low, high, zero, one, cur + one) % mod;
        return tmp % mod;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        return DFS(low, high, zero, one, 0);
    }
};

class Solution {
public:
    int mod = 1e9 + 7;
    unordered_set<string> tmp;
    int DFS(int low, int high, int zero, int one, int cur, vector<int>& memo) {
        if(cur > high)
            return 0;
        if(memo[cur] != -1)
            return memo[cur];
        long long tmp = 0;
        if(cur >= low && cur <= high)
            tmp++;

        tmp += DFS(low, high, zero, one, cur + zero, memo) % mod;
        tmp += DFS(low, high, zero, one, cur + one, memo) % mod;
        return memo[cur] = tmp % mod;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> memo(high + 1, -1);
        return DFS(low, high, zero, one, 0, memo);
    }
};

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1);
        dp[0] = 1;
        int md = 1e9 + 7;
        for (int i = min(zero, one); i <= high; i++) {
            if(i >= zero){
                dp[i] = (dp[i] + dp[i - zero]) % md;
            }
            if( i >= one){
                dp[i] = (dp[i] + dp[i - one]) % md;
            }
            
        }
        int sum = 0;
        for (int i = low; i <= high; i++) {
            sum = (sum + dp[i]) % md;
        }
        return sum;
    }
};