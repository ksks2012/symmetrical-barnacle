#include "include.h"

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> tmp;

        int res = INT_MAX;

        for (string time : timePoints) {
            int hour = stoi(time.substr(0, 2));
            int minute = stoi(time.substr(3, 2));
            tmp.push_back(hour * 60 + minute);
        }

        sort(tmp.begin(), tmp.end());

        for (int i = 1; i < tmp.size(); i++) {
            res = min(res, tmp[i] - tmp[i - 1]);
        }

        res = min(res, 1440 - tmp.back() + tmp[0]);

        return res;
    }
};