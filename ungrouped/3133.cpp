#include "include.h"

// lee
class Solution {
public:
    long long minEnd(int n, int x) {
        long long res = x;
        n--;
        while(n > 0) {
            res = (res + 1) | x;
            n--;
        }

        return res;
    }
};

class Solution {
public:
    long long minEnd(int n, int x) {
        n--;
        long long res = x, tmp;
        for (tmp = 1; n > 0; tmp <<= 1) {
            if ((tmp & x) == 0) {
                res |= (n & 1) * tmp;
                n >>= 1;
            }
        }
        return res;
    }
};