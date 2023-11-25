#include "../include.h"

// 26,18,6,12,49,7,45,45
// fast IO
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

class Solution {
private:
    int dp[1005];
    int F(int i, int n, vector<int> &prices){
        if(i >= n) return 0;
        if(dp[i] != -1) 
            return dp[i];
        int minCoins = 1e9;
        for(int j = i + 1; j <= min(n, 2 * (i + 1)); j++) 
            minCoins = min(minCoins, F(j, n, prices));
        return dp[i] = prices[i] + minCoins;
    }
public:
    int minimumCoins(vector<int>& prices){
        memset(dp, -1, sizeof dp);
        return F(0, prices.size(), prices);
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
            for(int j = i; j + j >= i  + 1; j --){
                dp[i + 1][0] = min(dp[i + 1][0] , dp[j][1]);
            }
        }
        return min(dp[n][0], dp[n][1]);
    }
};