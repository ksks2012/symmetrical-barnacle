#include "../include.h"


class Solution {
public:
    int maximumLengthSubstring(string s) {
        int tmp[26] = {0};
        int n = s.size();

        int left = 0;
        int res = 0;
        for(int right = 0; right < n; right++) {
            tmp[s[right] - 'a']++;
            while(tmp[s[right] - 'a'] > 2) {
                tmp[s[left] - 'a']--;
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};