#include "include.h"

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        bool s1CanBreak = true, s2CanBreak = true;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] < s2[i]) {
                s1CanBreak = false;
            }
            if (s1[i] > s2[i]) {
                s2CanBreak = false;
            }
        }
        return s1CanBreak || s2CanBreak;
    }
};