#include "include.h"

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double res = 0;

        int n = customers.size();
        long long totalWaitTime = 0;
        long long currentTime = 0;

        for (int i = 0; i < n; i++) {
            if (currentTime < customers[i][0]) {
                currentTime = customers[i][0] + customers[i][1];
            } else {
                currentTime += customers[i][1];
            }
            totalWaitTime += currentTime - customers[i][0];
        }

        res = (double)totalWaitTime / n;
        return res;
    }
};