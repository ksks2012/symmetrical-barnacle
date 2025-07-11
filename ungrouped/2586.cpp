#include "../include.h"

class Solution {
public:
    bool is_vowel[CHAR_MAX] = { false }; // initializes all values to false
    void init() {
        is_vowel['a'] = true;
        is_vowel['e'] = true;
        is_vowel['i'] = true;
        is_vowel['o'] = true;
        is_vowel['u'] = true;
    }

    int vowelStrings(vector<string>& words, int left, int right) {
        init();
        int count = 0;
        for (int i = left; i <= right; ++i) {
            const string& word = words[i];
            if (!word.empty() && is_vowel[word.front()] && is_vowel[word.back()]) {
                count++;
            }
        }
        return count;        
    }
};