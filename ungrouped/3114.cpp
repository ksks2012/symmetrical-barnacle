#include "include.h"

class Solution {
public:
    string findLatestTime(string s) {
        string res = s;

        if(res[0] == '?') {
            res[0] = (res[1] == '?' or res[1] - '0' < 2 ? '1' : '0');
        }
        if(res[1] == '?') {
            res[1] = (res[0] == '1' ? '1' : '9');
        }

        if(res[3] == '?') {
            res[3] = '5';
        } 
        if(res[4] == '?') {
            res[4] = '9';
        }

        return res;
    }
};