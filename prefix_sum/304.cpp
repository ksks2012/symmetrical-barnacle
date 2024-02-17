#include "include.h"

class NumMatrix {
public:
    int m, n;
    vector<vector<int>> vec;
    vector<vector<int>> sum;
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

    NumMatrix(vector<vector<int>>& matrix) {
        vec = matrix;
        this->m = vec.size();
        this->n = vec[0].size();
        
        sum = vector<vector<int>>(m, vector<int>(n, 0));
        // calculate the prefix sum
        prefixSum(vec, sum);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return get_sum(row2, col2, sum) - get_sum(row1 - 1, col2, sum) - get_sum(row2, col1 - 1, sum) + get_sum(row1 - 1, col1 - 1, sum);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */