#include "include.h"

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> row_mini(rows, INT_MAX), col_maxi(cols, INT_MIN), res;

        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j) {
                row_mini[i] = min(row_mini[i], matrix[i][j]);
                col_maxi[j] = max(col_maxi[j], matrix[i][j]);
            }

        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if (matrix[i][j] == row_mini[i] && matrix[i][j] == col_maxi[j])
                    res.push_back(matrix[i][j]);

        return res;
    }
};
