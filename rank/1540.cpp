#include "include.h"

// votrubac
class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if (s.size() != t.size())
            return false;

        // record shifted values
        int tmp[26] = {};

        for(int i = 0;i < s.size(); i++) {
            int shift = t[i] - s[i] + (t[i] < s[i] ? 26 : 0);
            if (shift != 0 && shift + tmp[shift] * 26 > k)
                return false;
            tmp[shift]++;
        }

        return true;
    }
};