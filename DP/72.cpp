#include "include.h"

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
    
        // Create a table to store the minimum edit distance between substrings of word1 and word2
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Initialize the table for the base cases
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    // Last characters match, no operation required
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // Insert a character into word1
                    int insertOp = dp[i][j - 1]; 
                    // Delete a character from word1
                    int deleteOp = dp[i - 1][j]; 
                    // Replace a character in word1 with a character in word2
                    int replaceOp = dp[i - 1][j - 1]; 
                    // Take the minimum of the three operations and add 1
                    dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
                }
            }
        }
    
        return dp[m][n];
    }
};

class Solution {
public:
    vector<vector<int>> memo;
    int minDistance(string word1, string word2) {
        memo.resize(word1.length() + 1, vector<int>(word2.length() + 1, -1));
        return minDistanceRecur(word1, word2, word1.size(), word2.size());
    }

    int minDistanceRecur(string &word1, string &word2, int word1Index, int word2Index) {
        if (word1Index == 0) {
            return word2Index;
        }
        if (word2Index == 0) {
            return word1Index;
        }
        if (memo[word1Index][word2Index] != -1) {
            return memo[word1Index][word2Index];
        }

        int minEditDistance = 0;
        if (word1[word1Index - 1] == word2[word2Index - 1]) {
            minEditDistance = minDistanceRecur(word1, word2, word1Index - 1, word2Index - 1);
        } else {
            int insertOperation = minDistanceRecur(word1, word2, word1Index, word2Index - 1);
            int deleteOperation = minDistanceRecur(word1, word2, word1Index - 1, word2Index);
            int replaceOperation = minDistanceRecur(word1, word2, word1Index - 1, word2Index - 1);
            minEditDistance = min(insertOperation, min(deleteOperation, replaceOperation)) + 1;
        }
        memo[word1Index][word2Index] = minEditDistance;
        return minEditDistance;
    }
};
