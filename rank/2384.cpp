#include "include.h"

class Solution {
public:
    string largestPalindromic(string num) {
        int m[10] = {};
        for(auto c: num) {
            m[c - '0']++;
        }

        string res = "";
        int maxi = -1;
        for(int i = 9; i >= 0; i--) {
            if(res.empty() && i == 0)
                continue;
            while(m[i] > 1) {
                res += i + '0';
                m[i] -= 2;
            }
            if(m[i] == 1 && maxi == -1) {
                maxi = i;
            }
        }

        string tmp = string(res.rbegin(), res.rend());
        if(res.empty() && maxi == -1) {
            return "0";
        }
        if(maxi != -1) {
            res += maxi + '0';
        }
        res += tmp;
        return res;        
    }
};