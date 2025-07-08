#include "../include.h"

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxOnes = 0;
        int rowIndex = -1;

        for (int i = 0; i < mat.size(); ++i) {
            int countOnes = count(mat[i].begin(), mat[i].end(), 1);
            if (countOnes > maxOnes) {
                maxOnes = countOnes;
                rowIndex = i;
            }
        }

        return {rowIndex, maxOnes};        
    }
};