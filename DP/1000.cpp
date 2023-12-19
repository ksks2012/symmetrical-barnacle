#include "include.h"

// DFS
class Solution {
public:
    int n;
    int k;
    vector<int> s;
    int DFS(int i, int j, int p) {
        if (p == 1) // merge to 1
            return i == j ? 0 : DFS(i, j, k) + s[j + 1] - s[i];
        int res = INT_MAX;
        for (int m = i; m < j; m += k - 1) // find stones to merge
            res = min(res, DFS(i, m, 1) + DFS(m + 1, j, p - 1));
        return res;
    }

    int mergeStones(vector<int> &stones, int k) {
        n = stones.size();
        this->k = k;
        if ((n - 1) % (k - 1)) // Can't be merged
            return -1;

        s = vector<int>(n + 1, 0);
        s[0] = 0;
        for (int i = 0; i < n; i++)
            s[i + 1] = s[i] + stones[i]; // Prefix sum

        return DFS(0, n - 1, 1);
    }
};

// DFS with memory
class Solution {
public:
    int n;
    int k;
    vector<int> s;
    int DFS(int i, int j, int p, vector<vector<vector<int>>>& memo) {
        int &res = memo[i][j][p];
        if(res != -1)
            return res;
        if (p == 1) // merge to 1
            return res = i == j ? 0 : DFS(i, j, k, memo) + s[j + 1] - s[i];
        res = INT_MAX;
        for (int m = i; m < j; m += k - 1) // find stones to merge
            res = min(res, DFS(i, m, 1, memo) + DFS(m + 1, j, p - 1, memo));
        return res;
    }

    int mergeStones(vector<int> &stones, int k) {
        n = stones.size();
        this->k = k;
        if ((n - 1) % (k - 1)) // Can't be merged
            return -1;

        s = vector<int>(n + 1, 0);
        s[0] = 0;
        for (int i = 0; i < n; i++)
            s[i + 1] = s[i] + stones[i]; // Prefix sum

        vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        return DFS(0, n - 1, 1, memo);
    }
};