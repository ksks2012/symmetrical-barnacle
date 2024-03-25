#include "include.h"

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();

        vector<long long> sum(n + 1, 0);
        for(int i = 1; i < n + 1; i++) {
            sum[i] = sum[i - 1] + differences[i - 1];
        }

        long long upper_range = upper - *max_element(sum.begin(), sum.end());
        long long lower_range = lower - *min_element(sum.begin(), sum.end());

        long long res = upper_range - lower_range + 1;
        return res > 0 ? res : 0;
    }
};