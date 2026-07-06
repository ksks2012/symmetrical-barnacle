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