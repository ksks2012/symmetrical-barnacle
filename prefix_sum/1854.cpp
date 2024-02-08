#include "include.h"

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int pop[2051] = {0}, ans = 0;
        for (auto &l : logs) {
            ++pop[l[0]];
            --pop[l[1]];
        }
        for (int i = 1950; i < 2050; ++i) {
            pop[i] += pop[i - 1];
            if(pop[i] > pop[ans])
                ans = i;
        }
        return ans;
    }
};