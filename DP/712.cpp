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