#include "include.h"

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int res = 0;
        int count_one = 0;

        for(auto c: s) {
            if(c == '1') {
                count_one++;
            } else {
                res++;
            }
            res = min(count_one, res);
        }

        return res;
    }
};