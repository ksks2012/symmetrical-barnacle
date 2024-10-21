#include "include.h"

class Solution {
public:
    int dfs(string s, unordered_set<string>& tmp) {
        if(s.size() == 0) {
            return tmp.size();
        }
        int ans = 0;
        for(int i = 1; i <= s.size(); i++) {
            string sub = s.substr(0, i);
            if(tmp.find(sub) == tmp.end()) {
                tmp.insert(sub);
                ans = max(ans, dfs(s.substr(i), tmp));
                tmp.erase(sub);
            }
        }
        return ans;
    }
    
    int maxUniqueSplit(string s) {
        unordered_set<string> tmp;
        return dfs(s, tmp);   
    }
};