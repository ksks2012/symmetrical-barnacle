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

        for(int right = 0, left = 0; right < n; right++) {
            if(--tmp[s[right] - 'a'] < k) {
                while(tmp[s[right] - 'a'] < k) {
                    ++tmp[s[left++] - 'a'];
                }
            }
            ans = max(ans, right - left + 1);
        }
        return n - ans;
    }
};