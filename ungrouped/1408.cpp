#include "include.h"

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> result;
        int n = (int)words.size();
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                if (i != j && words[i].find(words[j]) != string::npos) {
                    result.push_back(words[j]);
                    break;
                }
            }
        }
        return result;
    }
};