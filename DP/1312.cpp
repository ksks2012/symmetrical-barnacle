#include "include.h"

// DFS
class Solution {
public:
    string s;
    int n;

    int DFS(int i, int j) {
        if(i >= j)
            return 0;

        if(s[i] == s[j]) {
            return DFS(i + 1, j - 1);
        }
        return min(DFS(i + 1, j), DFS(i, j - 1)) + 1;
    }

    int minInsertions(string s) {
        this->s = s;
        n = s.size();

        return DFS(0, n - 1);
    }
};

// DFS with memory
class Solution {
public:
    string s;
    int n;

    int DFS(int i, int j, vector<vector<int>> &memo) {
        if(i >= j)
            return 0;

        int &res = memo[i][j];
        if(res != -1)
            return res;

        if(s[i] == s[j]) {
            return res = DFS(i + 1, j - 1, memo);
        }
        return res = min(DFS(i + 1, j, memo), DFS(i, j - 1, memo)) + 1;
    }

    int minInsertions(string s) {
        this->s = s;
        n = s.size();
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
        return DFS(0, n - 1, memo);
    }
};


// Iteration
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                if(s[j] == s[i])
                    dp[i][j] = dp[i + 1][j - 1];
                else
                    dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
            }
        }

        return dp[0][n - 1];
    }
};