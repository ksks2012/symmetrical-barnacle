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

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        m = mat.size();
        n = mat[0].size();
        vector<vector<int>> sum(m, vector<int>(n, 0));
        prefixSum(mat, sum);

        int maxi = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; i + k < m && j + k < n; k++) {
                    int tmp = get_sum(i + k, j + k, sum) - get_sum(i + k, j - 1, sum) - get_sum(i - 1, j + k, sum) + get_sum(i - 1, j - 1, sum);
                    if(tmp <= threshold) {
                        maxi = max(maxi, k + 1);
                    }
                }
            }
        }

        return maxi;
    }
};