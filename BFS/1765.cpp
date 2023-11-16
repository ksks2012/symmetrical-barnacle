#include "../include.h"

class Solution {
public:
    int way[5] = {0, 1, 0, -1, 0};
    vector<vector<int>> highestPeak(vector<vector<int>>& water) {
        vector<pair<int, int>> p;
        int level = 1, m = water.size(), n = water[0].size();
        // start from water
        for (auto i = 0; i < m; ++i) {
            for (auto j = 0; j < n; ++j) {
                water[i][j] = water[i][j] == 1 ? 0 : -1;
                if (water[i][j] == 0)
                    p.push_back({i, j});
            }
        }
            
        while (!p.empty()) {
            vector<pair<int, int>> tmp;
            for (auto [i, j] : p) {
                for (int d = 0; d < 4; ++d) {
                    int x = i + way[d], y = j + way[d + 1];
                    if (x >= 0 && y >= 0 && x < m && y < n && water[x][y] == -1) {
                        water[x][y] = level;
                        tmp.push_back({x, y});
                    }
                }
            }
            swap(p, tmp);
            ++level;
        }
        return water;
    }
};