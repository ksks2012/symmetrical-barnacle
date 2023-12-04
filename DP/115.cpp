#include "include.h"

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        
        vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0));

        for (int i = 0; i <= m; i++) 
            dp[i][0] = 1;

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        
        cout << "    ";
        for(int j = 1; j <= n; j++) {
            cout << t[j - 1] << " ";
        }
        cout << endl;
            
        for(int i = 0; i <= m; i++) {
            if(i >= 1)
                cout << s[i - 1] << " ";
            else
                cout << "  ";
            for(int j = 0; j <= n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[m][n];
    }      
};

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.length(), n = s.length();
        vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long> (n + 1, 0));
        for (int j = 0; j <= n; j++) 
            dp[0][j] = 1;
            
        for (int j = 1; j <= n; j++)
            for (int i = 1; i <= m; i++)
                dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0);
        return dp[m][n];
    }
};  

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.length(), n = s.length();
        vector<unsigned long long> cur(m + 1, 0);
        cur[0] = 1;
        for (int j = 1; j <= n; j++) { 
            int pre = 1;
            for (int i = 1; i <= m; i++) {
                int temp = cur[i];
                cur[i] = cur[i] + (t[i - 1] == s[j - 1] ? pre : 0);
                pre = temp;
            }
        }
        return cur[m];
    }
};