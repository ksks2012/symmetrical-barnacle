#include "include.h"

class Solution {
public:
    int minimumLength(string s) {
        vector<int> c_freq(26, 0);
        int res = 0;
        for (char cur : s) {
            c_freq[cur - 'a']++;
        }
        for (int freq : c_freq) {
            if (freq == 0) 
                continue; 
                
            if (freq % 2 == 0) {
                res += 2;
            } else {
                res += 1; 
            }
        }
        return res;
    }
};