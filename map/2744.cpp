#include "include.h"

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int res = 0;

        unordered_set<string> seen;
        for (const auto& word : words) {
            string rev_word = word;
            reverse(rev_word.begin(), rev_word.end());
            if (seen.count(rev_word)) {
                res++;
            } else {
                seen.insert(word);
            }
        }

        return res;
    }
};