#include "include.h"

// DFS 
class Solution {
 public:
    int DFS(string& s, int i, int j) {
        if (i >= j) 
            return 1;
        return s[i] == s[j] ? DFS(s, i + 1, j - 1) : 0;
    }

    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); ++i) {
            for(int j = i; j < s.size(); ++j) {
                count += DFS(s, i, j);
            }
        }
        return count;
    }
};

// DFS with memory
class Solution {
 public:
    int DFS(string& s, int i, int j, vector<vector<int>> &memo) {
        if (i >= j) 
            return 1;
        
        int &res = memo[i][j];

        if(res != -1 && s[i] == s[j])
            return res;
        else if (s[i] == s[j])
            return res = DFS(s, i + 1, j - 1, memo);

        return 0;
    }

    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
        for(int i = 0; i < s.size(); ++i) {
            for(int j = i; j < s.size(); ++j) {
                count += DFS(s, i, j, memo);
            }
        }
        return count;
    }
};


class Solution {
 public:
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;

        if (n <= 0)
            return 0;

        bool dp[n][n];
        fill_n(*dp, n * n, false);

        // Base case: single letter substrings
        for (int i = 0; i < n; ++i, ++ans)
            dp[i][i] = true;

        // Base case: double letter substrings
        for (int i = 0; i < n - 1; ++i) {
            dp[i][i + 1] = (s[i] == s[i + 1]);
            ans += dp[i][i + 1];
        }

        // All other cases: substrings of length 3 to n
        for (int len = 3; len <= n; ++len)
            for (int i = 0, j = i + len - 1; j < n; ++i, ++j) {
                dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
                ans += dp[i][j];
            }

        return ans;
    }
};