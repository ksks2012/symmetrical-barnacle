#include "include.h"

class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> maxi(n, 0);

        for(int j = 0; j < n; j++) {
            int tmp = 0;

            for(int i = 0; i < m; i++) {
                tmp = max(tmp, matrix[i][j]);
            }
            maxi[j] = tmp;
        }

        vector<vector<int>> ans = matrix;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(ans[i][j] == -1) {
                    ans[i][j] = maxi[j];
                }
            }
        }
        return ans;
    }
};