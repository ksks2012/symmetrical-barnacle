#include "include.h"

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> charCount;
        for (char c : chars) {
            charCount[c]++;
        }

        int totalLength = 0;
        for (const string& word : words) {
            unordered_map<char, int> wordCount;
            for (char c : word) {
                wordCount[c]++;
            }

            bool canForm = true;
            for (const auto& [c, count] : wordCount) {
                if (charCount[c] < count) {
                    canForm = false;
                    break;
                }
            }

            if (canForm) {
                totalLength += word.length();
            }
        }

        return totalLength;
    }
};

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int charCount[26] = {0};
        for (char c : chars) charCount[c - 'a']++;

        int totalLength = 0;
        for (const string& word : words) {
            int wordCount[26] = {0};
            bool canForm = true;
            for (char c : word) {
                if (++wordCount[c - 'a'] > charCount[c - 'a']) {
                    canForm = false;
                    break;
                }
            }
            if (canForm) totalLength += word.length();
        }
        return totalLength;
    }
};
