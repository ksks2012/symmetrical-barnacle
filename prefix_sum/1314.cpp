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

    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        m = mat.size();
        n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        vector<vector<int>> sum(m, vector<int>(n, 0));
        // Calculate prefix matrix 
        prefixSum(mat, sum);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = get_sum(i + k, j + k, sum) - get_sum(i + k, j - k - 1,sum) 
                    - get_sum(i - k - 1, j + k, sum) + get_sum(i - k - 1, j - k - 1, sum);
            }
        }

        return ans;
    }
};