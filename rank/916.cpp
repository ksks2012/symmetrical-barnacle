#include "../include.h"

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;

        vector<int> m(26, 0);
        for(int i = 0; i < words2.size(); i++) {
            vector<int> tmp(26, 0);
            for(char c: words2[i]) {
                tmp[c - 'a']++;
            }
            int j = 0;
            for (; j < 26; ++j) {
                m[j] = max(m[j], tmp[j]);
            }
        }

        vector<vector<int>> m1(words1.size(), vector<int>(26, 0));
        for(int i = 0; i < words1.size(); i++) {
            vector<int> tmp(26, 0);
            for(char c: words1[i]) {
                tmp[c - 'a']++;
            }
            int j = 0;
            for (; j < 26; ++j) {
                if (tmp[j] < m[j])
                    break;
            }

            if (j == 26) 
                res.push_back(words1[i]);
        }

        return res;
    }
};