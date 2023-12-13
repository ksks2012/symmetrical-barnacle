#include "include.h"

// DFS: TLE
class Solution {
public:
    string s, t;
    int m, n;

    int DFS(int i, int j) {
        if(j < 0)
            return 1;
        if(i < 0) 
            return 0;

        if(s[i] == t[j])
            return DFS(i - 1, j - 1) + DFS(i - 1, j);

        return DFS(i - 1, j);
    }

    int numDistinct(string s, string t) {
        m = s.size();
        n = t.size();
        this->s = s;
        this->t = t;

        return DFS(m - 1, n - 1);
    }      
};

class Solution {
public:
    string s, t;
    int m, n;

    int DFS(int i, int j, vector<vector<int>> &memo) {
        if(j < 0)
            return 1;
        if(i < 0) 
            return 0;

        int &res = memo[i][j];
        if(res != -1)
            return res;

        if(s[i] == t[j])
            return res = DFS(i - 1, j - 1, memo) + DFS(i - 1, j, memo);

        return res = DFS(i - 1, j, memo);
    }

    int numDistinct(string s, string t) {
        m = s.size();
        n = t.size();
        this->s = s;
        this->t = t;
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));

        return DFS(m - 1, n - 1, memo);
    }      
};

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