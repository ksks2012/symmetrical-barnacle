#include "include.h"

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> mp;
        unordered_set<string> ban(banned.begin(), banned.end());

        for (int i = 0; i < paragraph.size(); i++) {
            if (!isalpha(paragraph[i])) {
                continue;
            }

            int j = i;
            while (j < paragraph.size() && isalpha(paragraph[j])) {
                paragraph[j] = tolower(paragraph[j]);
                j++;
            }

            string word = paragraph.substr(i, j - i);
            if (ban.find(word) == ban.end()) {
                mp[word]++;
            }

            i = j;
        }

        return max_element(mp.begin(), mp.end(), [](auto& a, auto& b) {
            return a.second < b.second;
        })->first;
    }
};