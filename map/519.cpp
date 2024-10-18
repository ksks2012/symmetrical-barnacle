#include "include.h"

class Solution {
public:

    vector<vector<int>> matrix;

    int row = 0, col = 0;
    int total_row = 0, total_col = 0;

    Solution(int m, int n) {
        total_row = m;
        total_col = n;
    }
    
    vector<int> flip() {
        col++;
        if (col == total_col) {
            col = 0;
            row++;
        }
        if (row == total_row) {
            row = 0;
            col = 0;
        }

        return {row, col};
    }
    
    void reset() {
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */