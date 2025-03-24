#include "include.h"

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long res = 0;
        const int mod = 24;
        int tmp[mod]{};
        for (int i = 0; i < hours.size(); i++) {
            res += tmp[(mod - hours[i] % mod) % mod];
            tmp[hours[i] % mod]++;
        }
        return res;
    }
};