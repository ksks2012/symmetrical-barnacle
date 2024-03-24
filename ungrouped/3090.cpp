#include "include.h"

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int res = 0;

        int left = 0;
        int right = 0;

        unordered_map<char, int> m;

        while(right < s.length()) {
            m[s[right]]++;
            while(m[s[right]] > 2) {
                m[s[left]]--;
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }

        return res;
    }
};