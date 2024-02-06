#include "include.h"

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> sum(n + 1, 0);
        int tmp = 0;
        for(int i = 0; i < n; i++) {
            tmp += gain[i];
            sum[i + 1] = tmp;
        }
        return *max_element(sum.begin(), sum.end());
    }
};