#include "include.h"

class Solution {
public:
    long long numberOfWays(string s) {
        long long ans = 0;
        long long zero = 0, one = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '1') {
                one++;
            } else {
                zero++;
            }
        }
        long long cur_zero = 0, cur_one = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '1') {
                ans += (cur_one * zero);
                one--;
                cur_zero++;
            } else {
                ans += (cur_zero * one);
                zero--;
                cur_one++;
            }
        }

        return ans;
    }
};
