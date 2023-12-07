#include "include.h"

// DFS
class Solution {
public:
    string s;
    string t;
    int DFS(int i, int j) {
        if(i < 0 || j < 0) {
            return 0;
        }
        if(s[i] == t[j])
            return DFS(i - 1, j - 1) + 1;
        return max(DFS(i - 1, j), DFS(i, j - 1)); 
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        s = text1;
        t = text2;

        return DFS(m - 1, n - 1);
    }
};

// DFS with memo
class Solution {
public:
    string s;
    string t;
    int DFS(int i, int j, vector<vector<int>> &memo) {
        if(i < 0 || j < 0) {
            return 0;
        }
        int &res = memo[i][j];
        if(res != -1)
            return res;
        if(s[i] == t[j])
            return res = DFS(i - 1, j - 1, memo) + 1;
        return res = max(DFS(i - 1, j, memo), DFS(i, j - 1, memo)); 
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        s = text1;
        t = text2;

        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));

        return DFS(m - 1, n - 1, memo);
    }
};

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        if(m == 0 || n == 0)
            return 0;

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(text1[i] == text2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
        return dp[m][n];
    }
};

// Space Optimization
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        if(m == 0 || n == 0)
            return 0;

        vector<int> dp(n + 1);

        for(int i = 0; i < m; i++) {
            int prev = dp[0];
            for(int j = 0; j < n; j++) {
                int tmp = dp[j + 1];
                if(text1[i] == text2[j]) {
                    dp[j + 1] = prev + 1;
                } else {
                    dp[j + 1] = max(dp[j + 1], dp[j]);
                }
                prev = tmp;
            }
        }
        return dp[n];
    }
};