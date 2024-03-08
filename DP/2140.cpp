#include "../include.h"

class Solution {
public:
    int m, n;
    long long DFS(vector<vector<int>>& questions, int idx) {
        if(idx >= m)
            return 0;

        return max(DFS(questions, idx + questions[idx][1] + 1) + questions[idx][0], DFS(questions, idx + 1));
    }

    long long mostPoints(vector<vector<int>>& questions) {
        m = questions.size();
        n = 2;

        return DFS(questions, 0);
    }
};

// memo
class Solution {
public:
    int m, n;
    long long DFS(vector<vector<int>>& questions, int idx, vector<long long>& dp) {
        if(idx >= m)
            return 0;
        
        int res = dp[idx];
        if(res != -1)
            return res;

        return res = max(DFS(questions, idx + questions[idx][1] + 1, dp) + questions[idx][0], DFS(questions, idx + 1, dp));
    }

    long long mostPoints(vector<vector<int>>& questions) {
        m = questions.size();
        n = 2;

        vector<long long> dp(m + 1, -1);
        return DFS(questions, 0, dp);
    }
};

// DP
class Solution {
public:
    int m, n;
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(m + 1, 0);
        for(int i = n - 1; i >= 0 ; i--) {
            int point = questions[i][0];
            int jump = questions[i][1];

            int nextQuestion = min(n, i + jump + 1);
            dp[i] = max(dp[i + 1], point + dp[nextQuestion]);
        }
        return dp[0];
    }
};

// votrubac
class Solution {
public:
    int m, n;

    long long mostPoints(vector<vector<int>>& questions) {
        m = questions.size();
        n = 2;

        long long dp[200001] = {};
        for (int i = m - 1; i >= 0; --i)
            dp[i] = max(questions[i][0] + dp[questions[i][1] + i + 1], dp[i + 1]);
        return dp[0];
    }
};