#include "../include.h"

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        k = k % n;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i % 2 == 1) {
                    int tmp = (j + k) % n;
                    
                    if(mat[i][j] != mat[i][tmp])
                        return false;

                } else {
                    int tmp = (j - k);
                    if(tmp < 0)
                        tmp = n + tmp;
                    if(mat[i][j] != mat[i][tmp])
                        return false;
                }
            }
        }

        return true;
    }
};