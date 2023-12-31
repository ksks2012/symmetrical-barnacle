#include "../include.h"

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.empty()) return {};
        vector<int> res, m(256, 0);
        int left = 0, right = 0, cnt = p.size(), n = s.size();
        for (char c : p) 
            ++m[c];

        while (right < n) {
            if (m[s[right++]]-- >= 1) 
                --cnt;
            if (cnt == 0) 
                res.push_back(left);
            if (right - left == p.size() && m[s[left++]]++ >= 0) 
                ++cnt;
        }
        return res;
    }
};