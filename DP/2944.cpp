#include "../include.h"

// 26,18,6,12,49,7,45,45
// fast IO
static int n=[](){
 
    std::ios::sync_with_stdio(false);
 
    std::cin.tie(nullptr);
 
    return 0;
 
}();
class Solution {
public:
    void bc(vector<int>& prices, int &ans, int cur, int cur_sum, int free) {
        if(cur_sum > ans) {
            return;
        }
        if(cur == prices.size()) {
            ans = min(ans, cur_sum);
            return;
        }

        bc(prices, ans, cur + 1, cur_sum + prices[cur], cur + 1);
        if(free > 0) {
            bc(prices, ans, cur + 1, cur_sum, free - 1);
        }
    }

    int minimumCoins(vector<int>& prices) {
        int ans = INT_MAX;

        bc(prices, ans, 0, 0, 0);

        return ans;
    }
};

// Step 1: TLE
class Solution {
public:
    int DFS(vector<int>& prices, int cur) {
        int n = prices.size();
        if(cur >= n)
            return 0;

        int from = cur + 1;
        int to = from + cur + 1;

        int minCoins = 1e9;
        for(int j = from; j <= min(n, to); j++)
            minCoins = min(minCoins, DFS(prices, j));

        return prices[cur] + minCoins;
    }

    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        return DFS(prices, 0);
    }
};

// Step 2: memo
class Solution {
private:
    int dp[1005];
    int n;
    int DFS(int i, vector<int> &prices){
        if(i >= n) return 0;
        if(dp[i] != -1) 
            return dp[i];
        int minCoins = 1e9;
        for(int j = i + 1; j <= min(n, 2 * (i + 1)); j++) 
            minCoins = min(minCoins, DFS(j, prices));
        return dp[i] = prices[i] + minCoins;
    }
public:
    int minimumCoins(vector<int>& prices){
        n = prices.size();
        memset(dp, -1, sizeof dp);
        return DFS(0, prices);
    }
};

class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        int dp[1005][2];
        // initialize
        for(int i = 0 ; i <= n ; i ++){
            dp[i][0] = dp[i][1] = 999999;
        }
        dp[1][1] = prices[0];
        // dp
        for(int i = 1 ; i < n ; i ++){
            // buy i-th
            dp[i + 1][1] = min(dp[i][0] ,dp[i][1]) + prices[i];
            // not buy i-th
            for(int j = i; j + j >= i + 1; j--){
                dp[i + 1][0] = min(dp[i + 1][0] , dp[j][1]);
            }
        }
        return min(dp[n][0], dp[n][1]);
    }
};

class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[n] = 0;
        for(int i = n - 1; i >= 0; i--) {
            int from = i + 1;
            int to = from + i + 1;
            for(int j = from; j < min(to, n) + 1; j++) {
                dp[i] = min(dp[i], dp[j] + prices[i]);
            }
        }
        return dp[0];
    }
};