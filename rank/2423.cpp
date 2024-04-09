#include "../include.h"

// endlesscheng
class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char, int> m;
        for (char c: word)
            ++m[c];
        vector<int> count;
        for (auto &[_, c]: m)
            count.push_back(c);
        sort(count.begin(), count.end());
        // only one char or delete less freq or delete most freq
        return count.size() == 1 ||
               count[0] == 1 && equal(count.begin() + 2, count.end(), count.begin() + 1) ||
               count.back() == count[count.size() - 2] + 1 && equal(count.begin() + 1, count.end() - 1, count.begin());
    }
};