#include "include.h"

class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int all[3] = {0};

        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                all[grid[i][j]]++;
            }
        }   

        int y[3] = {0};
        int y_count = 0;

        // count Y values in grid
        for(int i = 0; i < m / 2; i++) {
            y[grid[i][i]]++;
            y[grid[i][m - i - 1]]++;
            y_count += 2;
        }
        for(int i = m / 2; i < m; i++) {
            y[grid[i][m / 2]]++;
            y_count++;
        }

        // calculate others
        for(int i = 0; i < 3; i++) {
            all[i] -= y[i];
        }

        int other = m * m - y_count;
        int ans = INT_MAX;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(i != j) {
                    int tmp = 0;
                    tmp += y_count - y[i];
                    tmp += other - all[j];
                    ans = min(ans, tmp);
                }
            }
        }

        return ans;
    }
};