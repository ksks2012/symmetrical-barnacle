#include "include.h"

// DFS
class Solution {
public:
    vector<int> values;
    int n;

    int DFS(int i, int j) {
        if (i + 1 == j) 
            return 0;

        int tmp = INT_MAX / 3;
        for(int k = i + 1; k < j; k++) {
            tmp = min(tmp, DFS(i, k) + DFS(k, j) + values[i] * values[j] * values[k]);
        }
        return tmp;
    }

    int minScoreTriangulation(vector<int>& values) {
        n = values.size();
        this->values = values;
        
        return DFS(0, n - 1);
    }
};

// DFS with memory: Time: O(n^3), Space: O(n^2)
class Solution {
public:
    vector<int> values;
    int n;

    int DFS(int i, int j, vector<vector<int>>& memo) {
        if (i + 1 == j) 
            return 0;

        int &res = memo[i][j];
        if(res != -1)
            return res;

        int tmp = INT_MAX / 3;
        for(int k = i + 1; k < j; k++) {
            tmp = min(tmp, DFS(i, k, memo) + DFS(k, j, memo) + values[i] * values[j] * values[k]);
        }
        return res = tmp;
    }

    int minScoreTriangulation(vector<int>& values) {
        n = values.size();
        this->values = values;
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
        return DFS(0, n - 1, memo);
    }
};

// Iteration
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = n - 3; i >= 0; i--) {
            dp[i][i] = 1;
            for(int j = i + 2; j < n; j++) {
                int tmp = INT_MAX / 3; 
                for(int k = i + 1; k < j; k++) {
                    tmp = min(tmp, dp[i][k] + dp[k][j] + values[i] * values[j] * values[k]);
                }
                dp[i][j] = tmp;
            }
        }

        return dp[0][n - 1];
    }
};
