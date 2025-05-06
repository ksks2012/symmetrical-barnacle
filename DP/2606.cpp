#include "../include.h"

class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int mp[26]{};
        iota(mp, mp + 26, 1);
        for (int i = 0; i < chars.length(); i++) {
            mp[chars[i] - 'a'] = vals[i];
        }

        int res = 0, f = 0;
        for (char c : s) {
            f = max(f, 0) + mp[c - 'a'];
            res = max(res, f);
        }
        return res;
    }
};
