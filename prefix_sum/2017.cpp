#include "include.h"

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
    long long top = accumulate(begin(grid[0]), end(grid[0]), 0ll), bottom = 0, res = LLONG_MAX;
    for(int i = 0; i < grid[0].size(); ++i) {
        top -= grid[0][i];
        res = min(res, max(top, bottom));
        bottom += grid[1][i];
    }
    return res;
}
};