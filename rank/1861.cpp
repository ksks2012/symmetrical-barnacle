#include "include.h"

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        vector<vector<char>> res(n, vector<char>(m));

        for(int i = 0; i < m; i++) {
            int tmp = 0;
            for(int j = 0; j < n; j++) {
                if(box[i][j] == '*') {
                    for(int k = 0; k < tmp; k++) {
                        box[i][j - 1 - k] = '#';
                    }
                    tmp = 0;
                }
                if(box[i][j] == '#') {
                    tmp++;
                    box[i][j] = '.';
                }
            }
            if(tmp != 0) {
                for(int k = 0; k < tmp; k++)
                    box[i][n  - 1 - k] = '#';
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                res[j][m - i - 1] = box[i][j];
            }
        }

        return res;
    }
};

// Optimization
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> res(n, vector<char>(m, '.'));
        for (int i = 0; i < m; ++i)
            for (int j = n - 1, k = n - 1; j >= 0; --j)
                if (box[i][j] != '.') {
                    k = box[i][j] == '*' ? j : k;
                    res[k--][m - i - 1] = box[i][j];
                }

        return res;
    }
};