#include "include.h"

class Solution {
public:
    int m, n;
    int get_sum(int i, int j, const vector<vector<long long> >& sum) {
        if (i < 0 || j < 0) 
            return 0;
        if (i >= m) 
            i = m - 1;
        if (j >= n) 
            j = n - 1;
        return sum[i][j];
    }
    
    void prefixSum(vector<vector<int>> &mat, vector<vector<long long>> &sum) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i][j] = (long long)mat[i][j] + get_sum(i - 1, j, sum) + get_sum(i, j - 1, sum) - get_sum(i - 1, j - 1, sum);
            }
        }
    }

    int maxSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<long long>> sum(m, vector<long long>(n, 0));
        prefixSum(grid, sum);

        int ans = 0;
        int k = 2;
        for (int i = 2; i < m; i++) {
            for (int j = 2; j < n; j++) {
                int nine = sum[i][j] - get_sum(i - k - 1, j, sum) - get_sum(i, j - k - 1, sum) + get_sum(i - k - 1, j - k - 1, sum);
                // Hourglass
                nine = nine - grid[i - 1][j] - grid[i - 1][j - 2];
                ans = max(ans, nine);
            }
        }
        return ans;
    }
};