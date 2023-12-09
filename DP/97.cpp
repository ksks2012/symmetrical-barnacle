#include "include.h"

// DFS
class Solution {
public:
    string s1, s2, s3;
    bool DFS(int i, int j, int k) {
        if(i < 0 && j < 0 && k < 0)
            return true;

        bool tmp = false;

        if(i >= 0 && s1[i] == s3[k]) {
            tmp = tmp || DFS(i - 1, j, k - 1);
        }
        if(j >= 0 && s2[j] == s3[k]) {
            tmp = tmp || DFS(i, j - 1, k - 1);
        }

        return tmp;
    }

    bool isInterleave(string s1, string s2, string s3) {
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;

        int x = s1.size();
        int y = s2.size();
        int z = s3.size();
        if(x + y != z)
            return false;

        return DFS(x - 1, y - 1, z - 1);
    }
};

// DFS with memo
class Solution {
public:
    string s1, s2, s3;
    bool DFS(int i, int j, int k, vector<vector<int>>&memo) {
        if(i < 0 && j < 0 && k < 0)
            return true;

        bool tmp = false;
        int &res = memo[i + 1][j + 1];
        if(res != -1)
            return res;

        if(i >= 0 && s1[i] == s3[k]) {
            tmp = tmp || DFS(i - 1, j, k - 1, memo);
        }
        if(j >= 0 && s2[j] == s3[k]) {
            tmp = tmp || DFS(i, j - 1, k - 1, memo);
        }
        res = tmp;

        return tmp;
    }

    bool isInterleave(string s1, string s2, string s3) {
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;

        int x = s1.size();
        int y = s2.size();
        int z = s3.size();
        if(x + y != z)
            return false;
        vector<vector<int>> memo(x + 1, vector<int>(y + 1, -1));
        return DFS(x - 1, y - 1, z - 1, memo);
    }
};

// 2D array of DP
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int x = s1.size();
        int y = s2.size();
        int z = s3.size();
        if(x + y != z)
            return false;
        vector<vector<bool>> dp(x + 1, vector<bool>(y + 1, false));
        dp[0][0] = true;

        for(int i = 0; i < x; i++) {
            dp[i + 1][0] = dp[i][0] && (s1[i] == s3[i]);
        }

        for(int j = 0; j < y; j++) {
            dp[0][j + 1] = dp[0][j] && (s2[j] == s3[j]);
        }

        int k = 0;
        for(int i = 0; i < x; i++) {
            for(int j = 0; j < y; j++) {
                k = i + j + 1;
                dp[i + 1][j + 1] = (dp[i][j + 1] && (s1[i] == s3[k])) || (dp[i + 1][j] && s2[j] == s3[k]);
            }
        }
        return dp[x][y];
    }
};

// Space Optimization
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int x = s1.size();
        int y = s2.size();
        int z = s3.size();
        if(x + y != z)
            return false;

        vector<bool> dp(y + 1, false);
        
        dp[0] = true;

        for(int j = 0; j < y; j++) {
            dp[j + 1] = dp[j] && (s2[j] == s3[j]);
        }

        int k = 0;
        for(int i = 0; i < x; i++) {
            dp[0] = dp[0] && (s1[i] == s3[i]);
            for(int j = 0; j < y; j++) {
                k = i + j + 1;
                dp[j + 1] = (dp[j + 1] && (s1[i] == s3[k])) || (dp[j] && s2[j] == s3[k]);
            }
        }

        return dp[y];
    }
};