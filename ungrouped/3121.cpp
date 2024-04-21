#include "include.h"

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int tmp[58] = {0};
        for(auto &t : tmp) {
            t = -1;
        }
        for(auto i = 0; i < word.length(); i++) {
            int idx = word[i] - 'A';
            if(idx <= 26 && tmp[idx] == -1) {
                tmp[idx] = i;
            } 
            if(idx >= 32) {
                tmp[idx] = i;
            }
        }

        int res = 0;
        for(int i = 0; i < 26; i++) {
            if(tmp[i] != -1 && tmp[i + 32] != -1 && tmp[i] > tmp[i + 32]) {
                res++;
            }
        }

        return res;
    }
};