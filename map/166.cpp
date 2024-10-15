#include "include.h"

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        
        string res;
        if ((numerator < 0) ^ (denominator < 0)) {
            res += "-";
        }

        long long num = abs((long long)numerator);
        long long denom = abs((long long)denominator);
        long long remainder = num % denom;

        res += to_string(num / denom);

        if (remainder == 0) {
            return res;
        }

        res += ".";
        unordered_map<long long, int> map;
        
        while (remainder != 0) {
            if (map.find(remainder) != map.end()) {
                res.insert(map[remainder], "(");
                res += ")";
                break;
            }

            map[remainder] = res.size();

            remainder *= 10;
            res += to_string(remainder / denom);
            remainder %= denom;
        }

        return res;
    }
};