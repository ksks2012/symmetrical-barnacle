#include "../include.h"

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> tmp(1001, 0);

        for(int i = 0; i < trips.size(); i++) {
            tmp[trips[i][1]] += trips[i][0];
            tmp[trips[i][2]] -= trips[i][0];
        }

        for(int i = 0; capacity >= 0 && i < tmp.size(); i++) {
            capacity -= tmp[i];
        }

        return capacity >= 0;
    }
};