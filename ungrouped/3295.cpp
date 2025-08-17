#include "include.h"

class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        int count = 0;
        set<string> bannedSets(bannedWords.begin(), bannedWords.end());
        for (const auto& word : message) {
            if (bannedSets.find(word) != bannedSets.end()) {
                count++;
            }
            if (count >= 2) {
                return true;
            }
        }
        return false;
    }
};