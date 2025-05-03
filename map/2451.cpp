#include "include.h"

class Solution {
public:
    string oddString(vector<string>& words) {
        for (int j = 0; j + 1 < words[0].size(); ++j) {
            unordered_map<int, vector<int>> mp;
            for (int i = 0; i < words.size(); ++i)
                mp[words[i][j + 1] - words[i][j]].push_back(i);
            if (mp.size() == 2)
                return words[begin(mp)->second.size() == 1 ? begin(mp)->second.back() : next(begin(mp))->second.back()];
        }
        return words[0];
    }
};