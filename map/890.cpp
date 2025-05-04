#include "include.h"

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        
        for(auto word : words) {
            unordered_map<char, char> map;
            unordered_map<char, char> map2;
            bool check = true;
            
            for(int i = 0; i < word.size(); i++) {
                if(map.find(word[i]) == map.end()) {
                    map[word[i]] = pattern[i];
                } else if(map[word[i]] != pattern[i]) {
                    check = false;
                    break;
                }
                
                if(map2.find(pattern[i]) == map2.end()) {
                    map2[pattern[i]] = word[i];
                } else if(map2[pattern[i]] != word[i]) {
                    check = false;
                    break;
                }
            }
            
            if(check) 
                res.push_back(word);
        }
        
        return res;
    }
};

// lee
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        auto encode = [](const string& s) {
            unordered_map<char, int> m;
            string res;
            for (char c : s) {
                if (!m.count(c)) m[c] = m.size();
                res += 'a' + m[c];
            }
            return res;
        };
        
        string p = encode(pattern);
        vector<string> ans;
        for (const string& w : words)
            if (encode(w) == p)
                ans.push_back(w);
        return ans;
    }
};