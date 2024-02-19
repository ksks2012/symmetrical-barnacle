#include "include.h"

class Solution {
public:
    int m, n;
    int get_sum(int i, int j, const vector<vector<int> >& sum) {
        if (i < 0 || j < 0) 
            return 0;
        if (i >= m) 
            i = m - 1;
        if (j >= n) 
            j = n - 1;
        return sum[i][j];
    }

    void prefixSum(vector<vector<int>> &mat, vector<vector<int>> &sum) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i][j] = mat[i][j] + get_sum(i - 1, j, sum) + get_sum(i, j - 1, sum) - get_sum(i - 1, j - 1, sum);
            }
        }
    }

    int sum_range(vector<vector<int>> &mat, int r1, int c1, int r2, int c2) {
        // r2 >= r1 && c1 >= c2
        return get_sum(r2, c2, mat) - get_sum(r2, c1 - 1, mat) - get_sum(r1 - 1, c2, mat) + get_sum(r1 - 1, c1 - 1, mat);
    }

    int cal_diagonal(vector<vector<int>> &mat, int r1, int c1, int k) {
        int tmp = 0;
        for(int i = 0; i <= k; i++) {
            tmp += mat[r1 + i][c1 + i];
        }
        return tmp;
    }

    bool check_diagonal(vector<vector<int>> &mat, int r1, int c1, int k, vector<vector<int>> &sum) {
        int dia1 = cal_diagonal(mat, r1, c1, k);
        // check diagonal with row first
        int tmp = sum_range(sum, r1, c1, r1, c1 + k);
        if(dia1 != tmp)
            return false;

        int dia2 = 0;
        for(int i = 0; i <= k; i++) {
            dia2 += mat[r1 + k - i][c1 + i];
        }
        return dia1 == dia2;
    }

    bool check_row(vector<vector<int>> &mat, int r1, int c1, int k) {
        if (k == 0)
            return true;
        int rowSum = sum_range(mat, r1, c1, r1, c1 + k);
        for (int i = 1; i <= k; i++) {
            int tmp = sum_range(mat, r1 + i, c1, r1 + i, c1 + k);
            if (tmp != rowSum) {
                return false;
            }
        }
        return true;
    }

    bool check_col(vector<vector<int>> &mat, int r1, int c1, int k) {
        if (k == 0)
            return true;

        int colSum = sum_range(mat, r1, c1, r1 + k, c1);
        for (int i = 1; i <= k; i++) {
            int tmp = sum_range(mat, r1, c1 + i, r1 + k, c1 + i);
            if (tmp != colSum) {
                return false;
            }
        }
        return true;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> sum(m, vector<int>(n, 0));
        prefixSum(grid, sum);

        int maxi = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; i + k < m && j + k < n; k++) {
                    if(check_diagonal(grid, i, j, k, sum) && check_row(sum, i, j, k) && check_col(sum, i, j, k)) {
                        maxi = max(maxi, k + 1);
                    }
                }
            }
        }

        return maxi;
    }
};

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<int>> rows(m + 2, vector<int>(n + 2)), cols(rows), d1(rows), d2(rows);
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j) {
                rows[i][j] += grid[i - 1][j - 1] + rows[i][j - 1];
                cols[i][j] += grid[i - 1][j - 1] + cols[i - 1][j];
                d1[i][j] += grid[i - 1][j - 1] + d1[i - 1][j - 1];
                d2[i][j] += grid[i - 1][j - 1] + d2[i - 1][j + 1];
            }
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                for (int k = min(m - i, n - j); k > res; --k) {
                    int sum = d1[i + k][j + k] - d1[i - 1][j - 1];
                    bool match = sum == d2[i + k][j] - d2[i - 1][j + k + 1]; 
                    for (int l = 0; l <= k && match; ++l) {
                        match &= sum == rows[i + l][j + k] - rows[i + l][j - 1];
                        match &= sum == cols[i + k][j + l] - cols[i - 1][j + l];
                    }
                    res = match ? k : res;
                }
        return res + 1;
    }
};