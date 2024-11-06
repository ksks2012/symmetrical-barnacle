#include "include.h"

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        unordered_map<string, int> seen;
        while (n > 0) {
            string cell_str = cellsToString(cells);
            
            if (seen.find(cell_str) != seen.end()) {
                n %= seen[cell_str] - n;
            }

            seen[cell_str] = n;
            
            // If N is even, then the cells will be the same after 1 day.
            if (n > 0) {
                n--;
                vector<int> new_cells(8, 0);
                for (int i = 1; i < 7; ++i) {
                    new_cells[i] = cells[i - 1] == cells[i + 1] ? 1 : 0;
                }
                cells = new_cells;
            }
        }
        return cells;
    }
    
private:
    string cellsToString(const vector<int>& cells) {
        string result;
        for (int cell : cells) {
            result += to_string(cell);
        }
        return result;
    }
};

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        for (n = (n - 1) % 14 + 1; n > 0; --n) {
            vector<int> tmp(8, 0);
            for (int i = 1; i < 7; ++i)
                tmp[i] = cells[i - 1] == cells[i + 1] ? 1 : 0;
            cells = tmp;
        }
        return cells;
    }
};
