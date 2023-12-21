#include "include.h"

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