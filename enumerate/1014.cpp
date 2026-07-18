#include "../include.h"

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxi = values[0];
        int res = 0;
        for(int j = 1; j < values.size(); j++) {
            res = max(res, maxi + values[j] - j);
            maxi = max(maxi, values[j] + j);
        }
        return res;
    }
};