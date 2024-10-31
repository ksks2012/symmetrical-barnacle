#include "../include.h"

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int res = 0, x = 0, y = 0, idx = 0;
        unordered_set<string> obs;
        for (auto a : obstacles) obs.insert(to_string(a[0]) + "-" + to_string(a[1]));
        vector<int> dir_x{0, 1, 0, -1}, dir_y{1, 0, -1, 0};
        for (int command : commands) {
            if (command == -1) idx = (idx + 1) % 4;
            else if (command == -2) idx = (idx - 1 + 4) % 4;
            else {
                while (command-- > 0 && !obs.count(to_string(x + dir_x[idx]) + "-" + to_string(y + dir_y[idx]))) {
                    x += dir_x[idx];
                    y += dir_y[idx];
                }
            }
            res = max(res, x * x + y * y);
        }
        return res;
    }
};
