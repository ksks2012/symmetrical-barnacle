#include "include.h"

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int tmp[58];
        for(auto i = 0; i < word.length(); i++) {
            tmp[word[i] - 'A']++;
        }
        int res = 0;

        for(int i = 0; i < 26; i++) {
            if(tmp[i] > 0 && tmp[i + 32] > 0) {
                res++;
            }
        }

        return res;
    }
};