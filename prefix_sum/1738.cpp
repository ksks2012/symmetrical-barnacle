#include "include.h"

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(),n = matrix[0].size();
        for(int i = 1; i < n; i++) {
            matrix[0][i] ^=matrix[0][i - 1];
        }

        for(int i = 1; i < m; i++) {
            matrix[i][0] ^= matrix[i - 1][0];
        }

        priority_queue<int> pq;
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                matrix[i][j] ^= matrix[i - 1][j] ^ matrix[i][j - 1] ^ matrix[i - 1][j - 1];
            }
        }
        

        for(int i = 0; i < 1; i++) {
            for(int j = 0; j < 1; j++) {
                pq.push(matrix[i][j]);
            }
        }

        while(!pq.empty()){
            k--;
            if(k == 0) 
                return pq.top();
            pq.pop();
        }

        return 0;
    }
};