#include "include.h"

// Backtracking
class Solution {
private:
    int ans;
    
    void helper(vector<vector<int>>& mat, vector<int> &chose, int c, int n, int m, int cols) {
        if(cols == 0) { // We choose all required columns
            int cntRows = cal_row(mat, chose, n, m);
            ans = max(ans, cntRows);
            return;
        }
        
        // if column size is exhausted and we haven't chosen the required amount of columns
        if(c >= m) { 
            return;
        }
        
        helper(mat, chose, c + 1, n, m, cols); // not choosing this column
        
		// choose this column
        chose[c] = 1; // mark this column
        helper(mat, chose, c + 1, n, m, cols - 1);
        chose[c] = 0; // unmark this column
    }
    
    int cal_row(vector<vector<int>>& mat, vector<int> &chose, int n, int m) {
        int count = 0;
        
        for(int i = 0; i < n; i++) {
            bool ok = 1;
            for(int j = 0; j < m; j++) {
				// If this cell in the ith row contains '1' but we haven't chosen this column, thus we cannot consider this row as covered
                if(mat[i][j] == 1 && chose[j] == 0) {
					ok = 0;
					break;
				}
            }
            if(ok) 
                count++;
        }
        
        return count;
    }
    
public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
        ans = 0;
        int n = mat.size(), m = mat[0].size();
        vector<int> chose(m, 0); // to track the chosen columns 
        helper(mat, chose, 0, n, m, cols);
        return ans;
    }
};

// endlesscheng
// Gosper's Hack
class Solution {
public:
    int maximumRows(vector<vector<int>> &mat, int cols) {
        int m = mat.size(), n = mat[0].size();
        vector<int> mask(m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mask[i] |= mat[i][j] << j;
            }
        }

        int ans = 0;
        int subset = (1 << cols) - 1;
        while (subset < (1 << n)) {
            int coveredRows = 0;
            for (int row : mask) {
                if ((row & subset) == row) {
                    coveredRows++;
                }
            }
            ans = max(ans, coveredRows);
            int lowbit = subset & -subset;
            int x = subset + lowbit;
            subset = ((subset ^ x) / lowbit >> 2) | x;
        }
        return ans;
    }
};