#include "include.h"

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int cnt = 0;

        map <int, int> r;
        map <int, int> c;
        map <int, pair<int, int>> loc;

        for(int i = 0; i < m; i++) {
            r[i] = 0;
            for (int j = 0; j < n; j++) {
                c[j] = 0;
                loc[mat[i][j]] = pair(i, j);
            }
        }

        for(int i = 0; i < m * n; i++) {
            int row = loc[arr[i]].first;
            int col = loc[arr[i]].second;
            r[row]++;
            if(r[row] == n) {
                return i;
            }
            c[col]++;
            if(c[col] == m) {
                return i;
            }
        }

        return m * n - 1;
    }
};