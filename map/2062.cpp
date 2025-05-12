#include "include.h"

class Solution {
public:
    int countVowelSubstrings(string w) {
        int tmp = 0, res = 0, mp[123] = {};
        string vowels("aeiou");
        for (int i = 0, j = 0, k = 0; i < w.size(); ++i) {
            if (vowels.find(w[i]) != string::npos) {
                tmp += ++mp[w[i]] == 1;
                for (; tmp == 5; ++k) {
                    tmp -= --mp[w[k]] == 0;
                }
                // we have k - j valid substrings
                res += k - j;
            }
            else {
                mp['a'] = mp['e'] = mp['i'] = mp['o'] = mp['u'] = tmp = 0;
                j = k = i + 1;
            }
        }
        return res;
    }
};