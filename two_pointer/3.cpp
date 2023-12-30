#include "include.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int n = s.length();
        if(n == 0)
            return 0;

        int left = 0;
        int tmp[128] = {0};

        for(int right = 0; right < n; right++) {
            tmp[s[right]]++;
            while(tmp[s[right]] > 1) {
                tmp[s[left]]--;
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};