#include "include.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows_rs[9];
        unordered_set<char> cols_rs[9];
        unordered_set<char> boxes_rs[9];

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    continue;
                }

                char value = board[r][c];
                int index = (r / 3) * 3 + (c / 3);

                if (rows_rs[r].count(value) || cols_rs[c].count(value) || boxes_rs[index].count(value)) {
                    return false;
                }

                rows_rs[r].insert(value);
                cols_rs[c].insert(value);
                boxes_rs[index].insert(value);
            }
        }

        return true;        
    }
};