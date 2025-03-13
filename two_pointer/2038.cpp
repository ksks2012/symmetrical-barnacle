#include "../include.h"

class Solution {
public:
    bool winnerOfGame(string colors) {
        int cnt[2] = {0, 0};
        int n = colors.size();
        for (int i = 0; i < n;) {
            int start = i;
            char c = colors[start];
            while (i < n && colors[i] == c) {
                i++;
            }
            int l = i - start;
            if (l > 2) {
                cnt[c - 'A'] += l - 2;
            }
        }
        return cnt[0] > cnt[1];
    }
};