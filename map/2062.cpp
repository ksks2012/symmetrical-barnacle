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


class Solution {
    static constexpr string VOWELS = "aeiou";

public:
    int countVowelSubstrings(string word) {
        unordered_map<char, int> mp;
        int res = 0, start = 0, left = 0;

        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (!VOWELS.contains(ch)) {
                mp.clear(); // reset
                start = left = i + 1;
                continue;
            }

            mp[ch]++;
            while (mp.size() == 5) { // window contains all vowels
                char out = word[left];
                mp[out]--;
                if (mp[out] == 0) {
                    mp.erase(out);
                }
                left++;
            }
            res += left - start;
        }

        return res;
    }
};