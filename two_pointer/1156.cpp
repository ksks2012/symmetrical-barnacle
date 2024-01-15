#include "include.h"

class Solution {
public:
    int maxRepOpt1(string text, int res = 0) {
        for (auto ch = 'a'; ch <= 'z'; ++ch) {
            int i = 0, j = 0, gap = 0;
            while (i < text.size()) {
                gap += text[i++] != ch;
                if (gap > 1) gap -= text[j++] != ch;
            }
            res = max(res, min(i - j, (int)count_if(begin(text), end(text), [&](char ch1) { return ch1 == ch; })));
        }
        return res;
    }
};