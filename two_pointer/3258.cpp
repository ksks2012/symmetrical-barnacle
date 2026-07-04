#include "include.h"

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size();
        int res = 0;

        int left = 0;
        int tmp[2] = {0};
        for(int right = 0; right < n; right++) {
            tmp[s[right] - '0']++;
            while(tmp[0] > k && tmp[1] > k) {
                tmp[s[left] - '0']--;
                left++;
            }
            res += right - left + 1;
        }

        return res;
    }
};