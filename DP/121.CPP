#include "include.h"

// DFS
class Solution {
public:
    vector<int> prices;
    int DFS(int i, int k, int hold) {
        if(k < 0) 
            return INT_MIN / 2; 
        if(i < 0) {
            if(hold)
                return INT_MIN / 2;
            return 0;
        }
        
        if(hold)
            return max(DFS(i - 1, k, 1), DFS(i - 1, k - 1, 0) - prices[i]);
        
        return max(DFS(i - 1, k, 0), DFS(i - 1, k, 1) + prices[i]);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        this->prices = prices;
        return DFS(n - 1, 1, 0);
    }
};

// DFS
class Solution {
public:
    vector<int> prices;
    int DFS(int i, int state) {
        if(i == prices.size() || state == 2) {
            return 0;
        }
        
        if(state == 0)
            return max(DFS(i + 1, state), DFS(i + 1, state + 1) - prices[i]);
        
        return max(DFS(i + 1, state), DFS(i + 1, state + 1) + prices[i]);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        this->prices = prices;
        return DFS(0, 0);
    }
};

// DFS with memo
class Solution {
public:
    vector<int> prices;
    int DFS(int i, int k, int hold, vector<vector<vector<int>>>& memo) {
        if(k < 0) 
            return INT_MIN / 2; 
        if(i < 0) {
            if(hold)
                return INT_MIN / 2;
            return 0;
        }

        int &res = memo[i][k][hold];
        if(res != -1)
            return res;
        
        if(hold)
            return res = max(DFS(i - 1, k, 1, memo), DFS(i - 1, k - 1, 0, memo) - prices[i]);
        
        return res = max(DFS(i - 1, k, 0, memo), DFS(i - 1, k, 1, memo) + prices[i]);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        this->prices = prices;
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(2, vector<int>(2, -1)));
        return DFS(n - 1, 1, 0, memo);
    }
};

// DFS with memo
class Solution {
public:
    vector<int> prices;
    int DFS(int i, int state, vector<vector<int>> &memo) {
        if(i == prices.size() || state == 2) {
            return 0;
        }
        int &res = memo[i][state];
        if(res != -1)
            return res;
        
        if(state == 0)
            return res = max(DFS(i + 1, state, memo), DFS(i + 1, state + 1, memo) - prices[i]);
        
        return res = max(DFS(i + 1, state, memo), DFS(i + 1, state + 1, memo) + prices[i]);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        this->prices = prices;
        vector<vector<int>> memo(n, vector<int>(4, -1));
        return DFS(0, 0, memo);
    }
};

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