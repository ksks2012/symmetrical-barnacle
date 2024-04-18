#include "include.h"

// Flood-Fill
class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        vector<vector<int>> res;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (land[i][j]) {
                    int x = i, y = j;
                    for (x = i; x < m && land[x][j]; ++x)
                        for (y = j; y < n && land[x][y]; ++y)
                            land[x][y] = 0;
                    res.push_back({i, j, x - 1, y - 1});
                }
            }
        return res;
    }
};

// Mark Left Side
vector<vector<int>> findFarmland(vector<vector<int>>& land) {
    int m = land.size(), n = land[0].size();
    vector<vector<int>> res;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            if (land[i][j] == 1) {
                int x = i, y = j;
                while (y < n && land[i][y])
                    ++y;                
                for (; x < m && land[x][j]; ++x)
                    land[x][j] = y - j + 1;
                res.push_back({i, j, x - 1, y - 1});
            }
            if (land[i][j] > 1)
                j += land[i][j] - 1;
        }
    return res;
}  