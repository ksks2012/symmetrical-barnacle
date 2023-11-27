#include "include.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices.size();
        int ans = 0;

        for (int i = 0; i < m - 1; i++) {
            for(int j = i + 1; j < m; j++) {
                if(prices[j] - prices[i] > ans) {
                    ans = prices[j] - prices[i];
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices.size();
        int buy = INT_MAX;
        int ans = 0;
        for(int i = 0; i < m; i++){
            buy = min(buy, prices[i]);
            ans = max(ans, prices[i] - buy); 
        }
        return ans;
    }
};