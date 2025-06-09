#include "../include.h"

// lee
class Solution {
public:
    int addMinimum(string word) {
        int res = 0, last = 'z';
        for (char c : word) {
            if (c <= last) ++res;
            last = c;
        }
        return res * 3 - word.size();
    }
};