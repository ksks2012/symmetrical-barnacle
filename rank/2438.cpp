#include "include.h"

# define MOD 1000000007
class Solution {
public:
    int modPow(int x, unsigned int y, unsigned int m) {
        if (y == 0)
            return 1;
        long p = modPow(x, y / 2, m) % m;
        p = (p * p) % m;
        return y % 2 ? (p * x) % m : p;
    }    

    vector<int> productQueries(int n, vector<vector<int>>& qs) {
        vector<int> pws{1}, res;
        for (int b = 0; b < 30; ++b)
            if (n & (1 << b))
                pws.push_back((1LL << b) * pws.back() % MOD);
        transform(begin(qs), end(qs), back_inserter(res), [&](const auto &q) { 
            return (long long)pws[q[1] + 1] * modPow(pws[q[0]], MOD - 2, MOD) % MOD; 
        });
        return res;
    }
};