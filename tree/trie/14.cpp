#include "include.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string& tmp = strs[0];
        for (int j = 0; j < tmp.size(); j++) {
            for (string& s : strs) {
                if (j == s.size() || s[j] != tmp[j]) {
                    return tmp.substr(0, j);
                }
            }
        }
        return tmp;
    }
};