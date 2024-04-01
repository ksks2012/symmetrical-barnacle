#include "include.h"

class Solution {
public:
    #define MOD 1000000007
    int left_most_one(int n) {
        int pos = 0;
    
        while (n) {
            n >>= 1;
            pos++;
        }
    
        return pos;
    }
    long long concatenatedBinary(int n) {
        // f(n) = f(n - 1) << log_2(n) + n
        if(n == 1)
            return 1;

        int left = left_most_one(n);        
        return (concatenatedBinary(n - 1) << left) % MOD + n;
    }
};

class Solution {
public:
    #define MOD 1000000007
    int concatenatedBinary(int n) {
        long long res = 0;
        
        int len = 1, power = 2;
        for (int i = 1; i <= n; ++i) {
            if(i == power){
                power <<= 1;
                len++;
            }
            res = ((res << len) % MOD + i) % MOD;
        }
        return res;
    }
};