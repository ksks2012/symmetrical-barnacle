#include "include.h"

// 1-D sweep
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> res(n, vector<int>(n));
        // Add value at the start of the segment,
        // Subtract that value after the end of the segment. 
        for (auto q : queries) {
            for (int i = q[0]; i <= q[2]; ++i) {
                res[i][q[1]] += 1;
                if (q[3] + 1 < n)
                    res[i][q[3] + 1] -= 1;
            }
        }
            
        for (int i = 0; i < n; ++i)
            partial_sum(begin(res[i]), end(res[i]), begin(res[i]));
        return res;
    }   
};

// 2-D sweep
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> res(n, vector<int>(n));
        // Add value at the start of the segment,
        // Subtract that value after the end of the segment. 
        for (auto q : queries) {
                int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
                ++res[r1][c1];
                // bottom left
                if (r2 + 1 < n)
                    --res[r2 + 1][c1];
                // top right
                if (c2 + 1 < n)
                    --res[r1][c2 + 1];
                // bottom right
                if (max(r2, c2) + 1 < n)
                    ++res[r2 + 1][c2 + 1];
        }
        // prefix sum: Left to right
        for (int i = 0; i < n; ++i)
            partial_sum(begin(res[i]), end(res[i]), begin(res[i]));  
        // prefix sum: Top to bottom
        for (int i = 1; i < n; ++i)
            for (int j = 0; j < n; ++j)
                res[i][j] += res[i - 1][j];         
        return res;
    }
};