#include "include.h"

// DFS
class Solution {
public:
    string s;
    int n;

    int DFS(int i, int j) {
        if (i == j) 
            return 1;
        else if(i > j)
            return 0;

        if(s[i] == s[j])
            return DFS(i + 1, j - 1) + 2;

        return max(DFS(i + 1, j), DFS(i, j - 1));
    }

    int longestPalindromeSubseq(string s) {
        n = s.size();
        this->s = s;
        
        return DFS(0, n - 1);
    }
};

// DFS with memory
class Solution {
public:
    string s;
    int n;

    int DFS(int i, int j, vector<vector<int>>& memo) {
        if (i == j) 
            return 1;
        else if(i > j)
            return 0;

        int &res = memo[i][j];
        if(res != -1)
            return res;

        if(s[i] == s[j])
            return res = DFS(i + 1, j - 1, memo) + 2;

        return res =max(DFS(i + 1, j, memo), DFS(i, j - 1, memo));
    }

    int longestPalindromeSubseq(string s) {
        n = s.size();
        this->s = s;
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
        return DFS(0, n - 1, memo);
    }
};

// Iteration
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for(int j = i + 1; j < n; j++) {
                if(s[j] == s[i])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }

        return dp[0][n - 1];
    }
};
