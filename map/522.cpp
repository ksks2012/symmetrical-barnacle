#include "include.h"

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        if (strs.empty()) 
            return -1;
        int res = -1;
        for(auto i = 0; i < strs.size(); ++i) {
            int j = 0;
            for(; j < strs.size(); ++j) {
                if(i == j) 
                    continue;
                if(LCS(strs[i], strs[j])) 
                    break;
            }
            if(j == strs.size()) 
                res = max(res, static_cast<int>(strs[i].size()));
        }
        return res;
    }

    bool LCS(const string& a, const string& b) {
        if (b.size() < a.size()) 
            return false;
        int i = 0;
        for(auto ch: b) {
            if(i < a.size() && a[i] == ch) 
                i++;
        }
        return i == a.size();
    }
};