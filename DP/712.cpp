#include "include.h"

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(int i = m - 1; i >= 0; i--) 
            dp[i][n] = dp[i + 1][n] + s1[i];
        
        for(int j = n - 1; j >= 0; j--) {
            dp[m][j] = dp[m][j + 1] + s2[j];
        } 
            
            
        for(int i = m - 1; i >= 0; i--)  {
            for(int j = n - 1; j >= 0; j--) {
                
                if(s1[i] == s2[j])
                    dp[i][j] = dp[i + 1][j + 1];
                else
                    dp[i][j] = min(dp[i + 1][j] + s1[i], dp[i][j + 1] + s2[j]);     
            }   
        }
         
        return dp[0][0];
    }
};

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(int i = 1; i <= m; i++) {
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
        }

        for(int j = 1; j <= n; j++) {
            dp[0][j] = dp[0][j - 1] + s2[j - 1];
        }
            
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
            }
        }
        return dp[m][n];
    }
};
// MLE
class Solution {
public:
    int computeCost(map<pair<int, int>, int> &storage, string s1, string s2, int i, int j) {
        if (i < 0 && j < 0) {
            return 0;
        }
        pair<int, int> key = pair<int, int>(i, j);

        // If already computed, then return the result from the hash map
        if(storage.find(key) != storage.end()) {
            return storage[key];
        }

        // If any one string is empty, delete all characters of the other string
        if (i < 0) {
            storage[key] = s2[j] + computeCost(storage, s1, s2, i, j - 1);
            return storage[key];
        }
        if (j < 0) {
            storage[key] = s1[i] + computeCost(storage, s1, s2, i - 1, j);
            return storage[key];
        }
        // Call sub-problem depending on s1[i] and s2[j]
        // Save the computed result.
        if (s1[i] == s2[j]) {
            storage[key] = computeCost(storage, s1, s2, i - 1, j - 1);
        } else {
            storage[key] = min(s1[i] + computeCost(storage, s1, s2, i - 1, j), s2[j] + computeCost(storage, s1, s2, i, j - 1));
        }
        return storage[key];
    }   

    int minimumDeleteSum(string s1, string s2) {
        map<pair<int, int>, int> storage;
        return computeCost(storage, s1, s2, s1.length() - 1, s2.length() - 1);
    }
};