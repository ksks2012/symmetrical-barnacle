#include "include.h"

class Solution {
public:
    bool is_vowels(char c) {
        return c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U';
    }

    string sortVowels(string s) {
        vector<char> tmp;

        for(int i = 0; i < s.length(); i++) {
            if(is_vowels(s[i])) {
                tmp.push_back(s[i]);
            }
        }
        sort(tmp.begin(), tmp.end());

        int j = 0;
        for(int i = 0; i < s.length(); i++) {
            if(is_vowels(s[i])) {
                s[i] = tmp[j++];
            }
        }

        return s;
    }
};