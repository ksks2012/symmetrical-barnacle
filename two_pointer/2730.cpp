#include "include.h"

// lee
class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int i = 0, cur = 0, n = s.length();
        for (int j = 1; j < n; ++j)
            if ((cur += s[j] == s[j - 1]) > 1)
                cur -= s[++i] == s[i - 1];
        return n - i;
    }
};

// endlesscheng
class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int ans = 1, left = 0, same = 0, n = s.length();
        for (int right = 1; right < n; right++) {
            if (s[right] == s[right - 1] && ++same > 1) {
                for (left++; s[left] != s[left - 1]; left++);
                same = 1;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};