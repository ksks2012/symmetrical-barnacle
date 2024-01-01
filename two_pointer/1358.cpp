#include "../include.h"

// abc
class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int n = s.size();

        int tmp[3] = {0};
        
        int left = 0;
        for(int right = 0; right < n; right++) {
            tmp[s[right] - 'a']++;
            while(tmp[0] >= 1 && tmp[1] >= 1 && tmp[2] >= 1) {
                ans += n - right;
                tmp[s[left] - 'a']--;
                left++;
            }
        }

        return ans;        
    }
};