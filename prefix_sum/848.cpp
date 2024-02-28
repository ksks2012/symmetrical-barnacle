#include "include.h"

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.length();
        vector<int> sum(n, 0);
        int cur = 0;
        for(int i = n - 1; i >= 0; i--) {
            cur += shifts[i];
            sum[i] = cur % 26;
        }

        for(int i = 0; i < s.size(); i++) {
            s[i] = (s[i] - 'a' + sum[i]) % 26 + 'a'; 
        }

        return s;
    }
};