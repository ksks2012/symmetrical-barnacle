#include "../include.h"

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> free(n + 1);
        free[0] = startTime[0]; // left
        for (int i = 1; i < n; i++) {
            free[i] = startTime[i] - endTime[i - 1]; // mid
        }
        free[n] = eventTime - endTime[n - 1]; // right

        int res = 0, tmp = 0;
        for (int right = 0; right <= n; right++) {
            tmp += free[right];
            if (right < k) {
                continue;
            }
            res = max(res, tmp);
            tmp -= free[right - k];
        }
        return res;
    }
};