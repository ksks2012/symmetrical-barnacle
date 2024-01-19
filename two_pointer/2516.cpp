#include "include.h"

class Solution {
public:
    int takeCharacters(string s, int k) {
        int tmp[3] = {0};
        int n = s.length();
        int ans = -1;
        for(auto c: s) {
            tmp[c - 'a']++;
        }

        if(*min_element(begin(tmp), end(tmp)) < k) {
            return -1;
        }

        for(int i = 0, j = 0; i < n; i++) {
            if(--tmp[s[i] - 'a'] < k) {
                while(tmp[s[i] - 'a'] < k) {
                    ++tmp[s[j++] - 'a'];
                }
            }
            ans = max(ans, i - j + 1);
        }
        return n - ans;
    }
};