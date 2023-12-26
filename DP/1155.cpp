#include "include.h"

// DFS
class Solution {
public:
    int DFS(int n, int k, int target) {
        if(target < 0)
            return 0;
        if(n < 0)
            if(target == 0)
                return 1;
            else
                return 0;

        int res = 0;
        for(int i = k; i >= 1; i--) {
            res += DFS(n - 1, k, target - i);
        }
        return res;
    }

    int numRollsToTarget(int n, int k, int target) {
        return DFS(n - 1, k, target);    
    }
};

class Solution {
public:
    int mod = 1000000007;
    int DFS(int n, int k, int target, vector<vector<int>> &memo) {
        if(target < 0)
            return 0;
        if(n < 0)
            if(target == 0)
                return 1;
            else
                return 0;

        int &res = memo[n][target];
        if(res != -1)
            return res;

        int tmp = 0;
        for(int i = k; i >= 1; i--) {
            tmp += DFS(n - 1, k, target - i, memo);
            tmp %= mod;
        }
        return res = tmp;
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> memo(n + 1, vector<int>(target + 1, -1));
        return DFS(n - 1, k, target, memo);    
    }
};

class Solution {
public:
    int mod = 1000000007;
    int DFS(int n, int k, int target, vector<vector<int>> &memo) {
        if(target < 0)
            return 0;
        if(n < 0)
            if(target == 0)
                return 1;
            else
                return 0;

        int &res = memo[n][target];
        if(res != -1)
            return res;

        int tmp = 0;
        for(int i = k; i >= 1; i--) {
            tmp += DFS(n - 1, k, target - i, memo);
            tmp %= mod;
        }
        return res = tmp;
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> memo(n + 1, vector<int>(target + 1, -1));
        return DFS(n - 1, k, target, memo);    
    }
};

// Iteration
class Solution {
public:
    int mod = 1000000007;
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        dp[0][0] = 1;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= target; j++) {
                for(int m = 1; m <= k; m++) {
                    if(m <= j) {
                        dp[i][j] = ((dp[i][j] % mod + dp[i - 1][j - m] % mod) % mod);
                    }
                        
                }
            }
        }
        return dp[n][target];    
    }
};

// Space Optimization
class Solution {
public:
    int mod = 1000000007;
    int numRollsToTarget(int n, int k, int target) {
        vector<int> dp(target + 1, 0);

        dp[0] = 1;

        for(int i = 1; i <= n; i++) {
            vector<int> dp1(target + 1, 0);
            for(int j = 1; j <= target; j++) {
                for(int m = 1; m <= k; m++) {
                    if(m <= j) {
                        dp1[j] = ((dp1[j] % mod + dp[j - m] % mod) % mod);
                    }
                }
            }
            swap(dp1, dp);
        }
        return dp[target];    
    }
};