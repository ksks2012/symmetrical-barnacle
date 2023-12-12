#include "include.h"

// TLE
class Solution {
public:
    vector<vector<int>> pairs;

    int DFS(int i, int pre) {
        if(i < 0)
            return 0;
        
        int tmp = 0;
        if(pre > pairs[i][1]) {
            tmp = DFS(i - 1, pairs[i][0]) + 1;
        }
        tmp = max(tmp, DFS(i - 1, pre));
        return tmp;
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        this->pairs = pairs;
        return DFS(n - 1, INT_MAX);
    }
};

class Solution {
public:
    vector<vector<int>> pairs;

    int DFS(int i, int pre, vector<vector<int>> &memo) {
        if(i < 0)
            return 0;
        
        int &res = memo[i][pre + 1000];
        if(res != -1)
            return res;
        
        int tmp = 0;
        if(pre > pairs[i][1]) {
            tmp = DFS(i - 1, pairs[i][0], memo) + 1;
        }
        tmp = max(tmp, DFS(i - 1, pre, memo));
        return res = tmp;
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        this->pairs = pairs;
        vector<vector<int>> memo(n, vector<int> (2002, -1));
        return DFS(n - 1, 1001, memo);
    }
};


class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> dp(n, 1);
        int ans = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (pairs[i][1] < pairs[j][0]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};