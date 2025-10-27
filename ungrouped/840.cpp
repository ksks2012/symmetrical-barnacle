#include "include.h"

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if (grid.size() < 3 || grid[0].size() < 3) return 0;
        int res = 0;
        for (int i = 0; i + 2 < (int)grid.size(); i++) {
            for (int j = 0; j + 2 < (int)grid[0].size(); j++) {
                if (isMagicSquare(grid, i, j)) {
                    res++;
                }
            }
        }
        return res;
    }

private:
    bool isMagicSquare(const vector<vector<int>>& grid, int row, int col) {
        set<int> s;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int val = grid[row + i][col + j];
                s.insert(val);
            }
        }
        if (s.size() != 9) return false;
        for (int k = 1; k <= 9; k++) {
            if (!s.count(k)) return false;
        }

        for (int i = 0; i < 3; i++) {
            int rsum = grid[row + i][col] + grid[row + i][col + 1] + grid[row + i][col + 2];
            if (rsum != 15) return false;
            int csum = grid[row][col + i] + grid[row + 1][col + i] + grid[row + 2][col + i];
            if (csum != 15) return false;
        }

        int diag1 = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
        int diag2 = grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col];
        if (diag1 != 15 || diag2 != 15) return false;

        return true;
    }
};