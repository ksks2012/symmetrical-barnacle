#include "include.h"

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> m;
        for(auto& word : words) {
            m[word]++;
        }
        int res = 0;
        int max_same = 0;
        for(auto p : m) {
            string s = p.first;
            reverse(s.begin(),s.end());
            if (p.first == s) {
                res += (int)p.second / 2 * 4;
                if(p.second % 2)
                    max_same = 2;
            } else if (m.count(s) != 0) {
                res += min(m[s], p.second) * 2;
            }
        }
        return res + max_same;
    }
};
