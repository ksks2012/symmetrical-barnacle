#include "../include.h"

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) {
            return false;
        }

        vector<int> m1(26, 0), m2(26, 0);
        set<int> s1, s2;
        
        for(auto c: word1) {
            m1[c - 'a']++;
            s1.insert(c);
        }
        for(auto c: word2) {
            m2[c - 'a']++;
            s2.insert(c);
        }
        sort(m1.begin(), m1.end());
        sort(m2.begin(), m2.end());

        return m1 == m2 && s1 == s2;
    }
};

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) {
            return false;
        }

        vector<int> m1(26, 0), m2(26, 0);
        
        for(auto c: word1) {
            m1[c - 'a']++;
        }
        for(auto c: word2) {
            m2[c - 'a']++;
        }
        sort(m1.begin(), m1.end());
        sort(m2.begin(), m2.end());

        return m1 == m2;
    }
};