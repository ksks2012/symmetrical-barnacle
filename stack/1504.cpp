#include "include.h"

class Solution {
public:
    int helper(vector<vector<int>>& mat, int x, int y) {
        int m = mat.size();
        int n = mat[0].size();
        int count = 0;
        int bound = n;
        
        for (int i = x; i< m; i++) {
            for (int j = y; j < bound; j++) {
                if (mat[i][j]) 
                    count += 1;
                else 
                    bound = j;
            }
        }
        
        return count;
    }

    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int res = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                res += helper(mat, i, j);
            }
        }

        return res;
    }
};

// lin
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int> > left(m, vector<int>(n));
        int now = 0;
        for(int i = 0; i < m; i++) {
            now = 0;
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 1) 
                    now++;
                else now = 0;
                    left[i][j] = now;
            }
        }
        int ans = 0, minx;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                minx = 0x3f3f3f3f;
                for(int k = i; k >= 0; k--) {
                    minx = min(left[k][j],minx);
                    ans += minx;
                }
            }
        }
        return ans;
    }
};

// Quantum
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            // count
            for (int j = i; j < m; j++) {
                int now = 0;
                for (int k = 0; k < n; k++) {
                    if (mat[j][k] == 0) now = 0;
                    else now = k == 0 ? mat[j][0] : now + 1;
                    res += now;
                }
            }
            // zip
            for (int j = m - 1; j > i; j--) {
                for (int k = 0; k < n; k++) {
                    mat[j][k] = mat[j][k] & mat[j - 1][k];
                }
            }
        }
        return res;
    }
};