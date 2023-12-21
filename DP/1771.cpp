#include "include.h"

// DFS: TLE
class Solution {
public:
    int m, n, s_size;
    string s;
    int tmp = 0;
    int DFS(int i, int j) {        
        if(i > j)
            return 0;
        if (i == j) 
            return 1;

        if(s[i] == s[j]) {
            int res = DFS(i + 1, j - 1) + 2;
            if(i < m && m <= j) {
                tmp = max(tmp, res);
            }
            return res;
        }
        return max(DFS(i + 1, j), DFS(i, j - 1));
    }

    int longestPalindrome(string word1, string word2) {
        s.append(word1);
        s.append(word2);

        s_size = s.length();
        m = word1.length();
        n = word2.length();

        DFS(0, s_size - 1);

        return tmp;
    }
};

class Solution {
public:
    int m, n, s_size;
    string s;
    int tmp = 0;
    int DFS(int i, int j, vector<vector<int>> &memo) {        
        if(i > j)
            return 0;
        if (i == j) 
            return 1;
        
        int &res = memo[i][j];
        if(res != -1)
            return res;

        if(s[i] == s[j]) {
            res = DFS(i + 1, j - 1, memo) + 2;
            if(i < m && m <= j) {
                tmp = max(tmp, res);
            }
            return res;
        }
        return res = max(DFS(i + 1, j, memo), DFS(i, j - 1, memo));
    }

    int longestPalindrome(string word1, string word2) {
        s.append(word1);
        s.append(word2);

        s_size = s.length();
        m = word1.length();
        n = word2.length();

        vector<vector<int>> memo(s_size + 1, vector<int>(s_size + 1, -1));
        DFS(0, s_size - 1, memo);

        return tmp;
    }
};

class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        string s;
        s.append(word1);
        s.append(word2);

        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        int ans = 0;
        for(int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for(int j = i + 1; j < n; j++) {
                if(s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                    if (i < word1.length() && j >= word1.length()) {
                        // dp[i][j] include s[i] and s[j]
                        ans = max(ans, dp[i][j]); 
                    }
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return ans;
    }
};