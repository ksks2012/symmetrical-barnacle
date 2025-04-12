#include "include.h"

class Solution {
public:
    bool isValid(string s) {
        int i = 0;
        for (char c: s) {
            if (c > 'a' && (i == 0 || c - s[--i] != 1))
                return false;
            if (c < 'c')
                s[i++] = c;
        }
        return i == 0;
    }
};