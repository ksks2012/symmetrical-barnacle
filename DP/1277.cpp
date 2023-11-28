#include "include.h"

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int ans = 0;

        int sq = 1;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] != 0) {
                    int tmp_x = i + 1;
                    int tmp_y = j + 1;
                    if(tmp_x < m && tmp_y < n) {
                        matrix[i][j] = min(matrix[i][j], min(matrix[i][tmp_y], (matrix[tmp_x][j]))) + 1;
                    }
                }
            }
        }

        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans += matrix[i][j];
            }
        }

        return ans;
    }
};