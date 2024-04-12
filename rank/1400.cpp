#include "../include.h"

class Solution {
public:
    bool canConstruct(string s, int k) {
        int m[26] = {};
        for(int i = 0; i < s.size(); i++) {
            m[s[i] - 'a']++;
        }

        int odd = 0;
        for(int i = 0; i < 26; i++) {
            if(m[i] % 2 == 1)
                odd++;
        }

        return odd <= k && k <= s.size();
    }
};