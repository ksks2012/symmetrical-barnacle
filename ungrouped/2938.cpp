#include "include.h"

class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();

        long long res = 0;

        int one = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                res += one;
            } else if (s[i] == '1') {
                one++;
            }
        }

        return res;
    }
};