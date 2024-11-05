#include "../include.h"

class Solution {
public:
    int minChanges(string s) {
        int res = 0;
        int n = s.size();

        for (int i = 0; i < n - 1; i += 2) {
            if (s[i] != s[i + 1]) {
                res++;
            }
        }

        return res++;
    }
};