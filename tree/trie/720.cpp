#include "include.h"

class Solution {
public:
    string longestWord(vector<string>& words) {
        string res = "";
        int maxi_len = 0;
        unordered_set<string> s(words.begin(), words.end());
        queue<string> q;
        for (string word : words) {
            if (word.size() == 1) q.push(word);
        }
        while (!q.empty()) {
            string tmp = q.front(); q.pop();
            if (tmp.size() > maxi_len) {
                maxi_len = tmp.size();
                res = tmp;
            } else if (tmp.size() == maxi_len) {
                res = min(res, tmp);
            }
            for (char c = 'a'; c <= 'z'; ++c) {
                tmp.push_back(c);
                if (s.count(tmp)) q.push(tmp);
                tmp.pop_back();
            }
        }
        return res;
    }
};