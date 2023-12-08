#include "include.h"

// TLE
class Solution {
public:
    string s;
    string t;
    int DFS(int i, int j) {
        if(i < 0)
            return j + 1;
        if(j < 0)
            return i + 1;
        
        if(s[i] == t[j])
            return DFS(i - 1, j - 1);
        return min(DFS(i - 1, j - 1) + 2, min(DFS(i, j - 1) + 1, DFS(i - 1, j) + 1));
    }

    int minDistance(string a, string b) {
        int m = a.size();
        int n = b.size();

        s = a;
        t = b;

        return DFS(m - 1, n - 1);
    }
};

// DFS with memo
class Solution {
public:
    string s;
    string t;
    int DFS(int i, int j, vector<vector<int>>& memo) {
        if(i < 0)
            return j + 1;
        if(j < 0)
            return i + 1;
        
        int &res = memo[i][j];
        if(res != -1)
            return res;
        
        if(s[i] == t[j])
            return res = DFS(i - 1, j - 1, memo);
        return res = min(DFS(i - 1, j - 1, memo) + 2, min(DFS(i, j - 1, memo) + 1, DFS(i - 1, j, memo) + 1));
    }

    int minDistance(string a, string b) {
        int m = a.size();
        int n = b.size();

        s = a;
        t = b;
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
        return DFS(m - 1, n - 1, memo);
    }
};


class Solution {
public:
    int minDistance(string s, string t) {
        int m = s.size();
        int n = t.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(s[i] == t[j]) {
                    dp[i + 1][j + 1] = dp[i][j];
                } else {
                    dp[i + 1][j + 1] = min(dp[i][j] + 2, min(dp[i + 1][j], dp[i][j + 1]) + 1);
                }
            }
        }

        return dp[m][n];
    }
};

// Space Optimization
class Solution {
public:
    int minDistance(string s, string t) {
        int m = s.size();
        int n = t.size();

        vector<int> dp(n + 1, 0);

        for (int j = 0; j <= n; j++) {
            dp[j] = j;
        }
        
        for(int i = 0; i < m; i++) {
            int prev = dp[0];
            dp[0]++;
            for(int j = 0; j < n; j++) {
                int tmp = dp[j + 1];
                if(s[i] == t[j]) {
                    dp[j + 1] = prev;
                } else {
                    dp[j + 1] = min(prev + 2, min(dp[j], dp[j + 1]) + 1);
                }
                prev = tmp;
            }
        }

        return dp[n];
    }
};