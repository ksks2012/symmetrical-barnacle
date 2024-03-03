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

    int countSubmatrices(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> sum(m, vector<int>(n, 0));
        prefixSum(grid, sum);

        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int tmp = sum_range(sum, 0, 0, i, j);
                if(tmp <= k) {
                    ans++;
                }
            }
        }

        return ans;

    }
};