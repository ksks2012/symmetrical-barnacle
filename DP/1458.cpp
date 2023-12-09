#include "include.h"

// DFS
class Solution {
public:
    vector<int> A, B;
    int DFS(int i, int j) {
        if(i < 0 || j < 0)
            return INT_MAX / 2 * -1;

        return max(max(DFS(i - 1, j - 1), 0) + A[i] * B[j], max(DFS(i - 1, j), DFS(i, j - 1)));
    }

    int maxDotProduct(vector<int>& A, vector<int>& B) {
        this->A = A;
        this->B = B;

        int m = A.size();
        int n = B.size();

        return DFS(m - 1, n - 1);
    }
};

// DFS with memory
class Solution {
public:
    vector<int> A, B;
    int sp = INT_MAX / 2 * -1;
    int DFS(int i, int j, vector<vector<int>> &memo) {
        if(i < 0 || j < 0)
            return sp;

        int & res = memo[i][j];
        if(res != sp)
            return res;
        return res = max(max(DFS(i - 1, j - 1, memo), 0) + A[i] * B[j], max(DFS(i - 1, j, memo), DFS(i, j - 1, memo)));
    }

    int maxDotProduct(vector<int>& A, vector<int>& B) {
        this->A = A;
        this->B = B;

        int m = A.size();
        int n = B.size();
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, sp));
        return DFS(m - 1, n - 1, memo);
    }
};

// 2D array of DP
class Solution {
public:
    int sp = INT_MAX / 2 * -1;
    int maxDotProduct(vector<int>& A, vector<int>& B) {
        int m = A.size();
        int n = B.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, sp));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i + 1][j + 1] = max(max(dp[i][j], 0) + A[i] * B[j], max(dp[i][j + 1], dp[i + 1][j]));
            }
        }

        return dp[m][n];
    }
};

// Space Optimization
class Solution {
public:
    int sp = INT_MAX / 2 * -1;
    int maxDotProduct(vector<int>& A, vector<int>& B) {
        int m = A.size();
        int n = B.size();
        vector<int> dp(n + 1, sp);
        for (int i = 0; i < m; i++) {
            int prev = dp[0];
            for (int j = 0; j < n; j++) {
                int tmp = dp[j+1];
                dp[j + 1] = max(max(prev, 0) + A[i] * B[j], max(dp[j + 1], dp[j]));
                prev = tmp;
            }
            
        }

        return dp[n];
    }
};



class Solution {
public:
    int maxDotProduct(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dp[i][j] = A[i] * B[j];
                if (i && j) dp[i][j] += max(dp[i - 1][j - 1], 0);
                if (i) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                if (j) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
        }
        return dp[n - 1][m - 1];
    }
};