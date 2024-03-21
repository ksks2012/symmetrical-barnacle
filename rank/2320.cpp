#include "../include.h"

#define MOD 1000000007
class Solution {
public:
    int countHousePlacements(int n) {
        if(n == 1)
            return 4;
        if(n == 2)
            return 9;

        long long prev_prev = 2;
        long long prev = 3;
        for(int i = 3; i < n + 1; i++) {
            long long cur = prev + prev_prev;
            prev_prev = prev % MOD;
            prev = cur % MOD;
        }
        return (prev * prev) % MOD;
    }
};