#include "../include.h"

class Solution {
public:
    string VOWELS = "aeiou";
    long long helper(string word, int k) {
        int n = word.length();
        long long res = 0;
        int left = 0;
        int count = 0;

        unordered_map<char, int> mp;
        for(int right = 0; right < n; right++) {
            if(VOWELS.find(word[right]) != string::npos) {
                mp[word[right]]++;
            } else {
                count++;
            }
            while(mp.size() == 5 && count >= k) {
                if(VOWELS.find(word[left]) != string::npos) {
                    mp[word[left]]--;
                    if(mp[word[left]] == 0) {
                        mp.erase(word[left]);
                    }
                } else {
                    count--;
                }

                left++;
            }
            res += left;
        }

        return res;
    }

    long long countOfSubstrings(string word, int k) {
        return helper(word, k) - helper(word, k + 1);
    }
};

// op
class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        const int VOWEL_MASK = 1065233;  // aeiou 
        long long res = 0;
        
        int cnt_v1[26] = {}, size_v1 = 0, cons1 = 0, left1 = 0;
        int cnt_v2[26] = {}, size_v2 = 0, cons2 = 0, left2 = 0;
        
        for (char ch : word) {
            int b = ch - 'a';
            
            if (VOWEL_MASK >> b & 1) {
                if (cnt_v1[b]++ == 0) size_v1++;
                if (cnt_v2[b]++ == 0) size_v2++;
            } else {
                cons1++;
                cons2++;
            }
            
            // all vowels + consonants >= k
            while (size_v1 == 5 && cons1 >= k && left1 <= word.size()) {
                int out = word[left1] - 'a';
                if (VOWEL_MASK >> out & 1) {
                    if (--cnt_v1[out] == 0) size_v1--;
                } else {
                    cons1--;
                }
                left1++;
            }

            // all vowels + consonants > k
            while (size_v2 == 5 && cons2 > k && left2 <= word.size()) {
                int out = word[left2] - 'a';
                if (VOWEL_MASK >> out & 1) {
                    if (--cnt_v2[out] == 0) size_v2--;
                } else {
                    cons2--;
                }
                left2++;
            }
            res += left1 - left2;
        }
        
        return res;
    }
};