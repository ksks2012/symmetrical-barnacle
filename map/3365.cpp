#include "include.h"
#include <unordered_map>

// Split and count substrings
class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n = s.size();
        int l = n / k;

        unordered_map<string, int> c1, c2;

        for (int i = 0; i < n; i += l) {
            string sub_s = s.substr(i, l);
            c1[sub_s]++;
        }

        for (int i = 0; i < n; i += l) {
            string sub_t = t.substr(i, l);
            c2[sub_t]++;
        }

        return c1 == c2;
    }
};
