
#include "include.h"

class Solution {
public:
    string longestNiceSubstring(string s) {
        if (s.size() < 2) 
            return "";
            
        unordered_set<char> tmp(begin(s), end(s));
        for (int i = 0; i < s.size(); i++) {
            if (tmp.find((char) toupper(s[i])) == end(tmp) || tmp.find((char) tolower(s[i])) == end(tmp)) {
                string s1 = longestNiceSubstring(s.substr(0, i));
                string s2 = longestNiceSubstring(s.substr(i + 1));
                return s1.size() >= s2.size() ? s1 : s2;
            }
        }
        return s;
    }
};