#include "include.h"

class Solution {
    void better(int &x, int y) {
        if (x == 0 || x > y) {
            x = y;
        }
    }
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> bad;
        const int n = backs.size();
        for (int i = 0; i < n; ++i) {
            if (fronts[i] == backs[i]) {
                bad.insert(backs[i]);
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (!bad.count(fronts[i])) {
                better(res, fronts[i]);
            }
            if (!bad.count(backs[i])) {
                better(res, backs[i]);
            }
        }
        return res;
    }
};