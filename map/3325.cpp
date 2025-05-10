#include "include.h"

class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.length(), res = (n + 1) * n / 2;
        unordered_map<char, int> mp;
        for (int i = 0, j = 0; j < n; j++) {
            mp[s[j]]++;
            while (mp[s[j]] >= k)
                --mp[s[i++]];
            res -= j - i + 1;
        }
        return res;
    }
};