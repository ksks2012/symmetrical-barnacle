#include "include.h"

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string res = "";

        unordered_map<string, string> mp;
        for (auto& k : knowledge) {
            mp[k[0]] = k[1];
        }
        
        for(int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                string key = "";
                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }
                // key += ')';
                
                if(mp.empty()) {
                    res += '?';
                    continue;
                }
                
                if(mp.find(key.substr(1)) != mp.end()) {
                    res += mp[key.substr(1)];
                } else {
                    res += '?';
                }
            } else {
                res += s[i];
            }
        }
        
        return res;
    }
};