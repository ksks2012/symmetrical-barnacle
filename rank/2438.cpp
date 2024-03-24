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

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> pws{1}, res;
        for (int b = 0; b < 30; ++b)
            if (n & (1 << b))
                pws.push_back((1LL << b) * pws.back() % MOD);
        transform(begin(queries), end(queries), back_inserter(res), [&](const auto &q) { 
            return (long long)pws[q[1] + 1] * modPow(pws[q[0]], MOD - 2, MOD) % MOD; 
        });
        return res;
    }
};

// brute force
# define MOD 1000000007
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> a;
        while (n > 0) {
            int lowbit = n & -n;
            a.push_back(lowbit);
            n ^= lowbit;
        }
        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int mul = 1;
            for (int j = queries[i][0]; j <= queries[i][1]; ++j) {
                mul = (1LL * mul * a[j]) % MOD;
            }
            res[i] = mul;
        }
        return res;
    }
};