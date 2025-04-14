#include "include.h"

class Solution {
public:
    int countCollisions(string directions) {
        int right = 0, res = 0, check = false;
        for (char d : directions)
            if (d == 'R')
                ++right;
            else if (d == 'S') {
                res += right;
                right = 0;
                check = true;
            }
            else {
                if (right > 0) {
                    res += right + 1;
                    right = 0;
                    check = true;
                }
                else if (check)
                    ++res;
            }
        return res;
    }
};