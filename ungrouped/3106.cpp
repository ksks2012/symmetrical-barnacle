#include "include.h"

class Solution {
public:
    string getSmallestString(string s, int k) {
        if(k == 0) {
            return s;
        }

        string res = s;
        int idx = 0;
        while(k != 0 && idx < s.size()) {
            int diff = 26 - (s[idx] - 'a');
            if(diff <= k && 26 - diff > diff) {
                res[idx] = (s[idx] - 'a' + diff) % 26 + 'a';
                k -= diff;
            } else if(26 - diff < k) {
                res[idx] = (s[idx] - 'a' - (26 - diff)) % 26 + 'a';
                k -= 26 - diff;
            } else {
                res[idx] = (s[idx] - 'a' - (k)) % 26 + 'a';
                k = 0 ;
            }
            idx++;
        }


        return res;
    }
};