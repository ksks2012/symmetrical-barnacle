#include "include.h"

class Solution {
    const string VOWEL = "aeiou";

    long long f(string& word, int k) {
        long long res = 0;
        // NOTE: Here a hash map is used; replacing it with an array would be faster
        unordered_map<char, int> cnt1; // Count of each vowel
        int cnt2 = 0; // Number of consonants
        int left = 0;
        for (char b : word) {
            if (VOWEL.find(b) != string::npos) {
                cnt1[b]++;
            } else {
                cnt2++;
            }
            while (cnt1.size() == 5 && cnt2 >= k) {
                char out = word[left];
                if (VOWEL.find(out) != string::npos) {
                    if (--cnt1[out] == 0) {
                        cnt1.erase(out);
                    }
                } else {
                    cnt2--;
                }
                left++;
            }
            res += left;
        }
        return res;
    }

public:
    long long countOfSubstrings(string word, int k) {
        return f(word, k) - f(word, k + 1);
    }
};
