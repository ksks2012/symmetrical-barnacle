#include "include.h"

// Solution
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& p) {
        int res = 0, n = p.size();
        sort(begin(p), end(p), [](const auto &p1, const auto &p2){
            return p1[0] == p2[0] ? p1[1] > p2[1] : p1[0] < p2[0];
        });
        for (int i = 0; i < n; ++i)
            for (int j = i + 1, y = INT_MIN; j < n; ++j)
                if (p[i][1] >= p[j][1] && y < p[j][1]) {
                    ++res;
                    y = p[j][1];
                }
        return res;
    }
};