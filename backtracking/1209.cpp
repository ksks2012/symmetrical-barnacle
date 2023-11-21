#include "include.h"

// deeedbbcccbdaa
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<char> sta;
        stack<int> cnt;
        string ans = "";
        
        for(int i = 0; i < s.length(); i++) {
            int tmp = 1;
            if(!sta.empty() && s[i] == sta.top()) {
                tmp = cnt.top() + 1;
            }
            if(tmp == k) {
                for(int j = 0; j < k - 1; j++) {
                    sta.pop();
                    cnt.pop();
                }
            } else {
                sta.push(s[i]);
                cnt.push(tmp);
            }

        } 

        while(!sta.empty()) {
            ans = sta.top() + ans;
            sta.pop();
        }

        return ans;   
    }
};

class Solution {
public:
    string removeDuplicates(string s, int k) {
        // empty
        vector<pair<int, char>> sta = {{0, '#'}};
        for(auto c: s) {
            if(c == sta.back().second) {
                sta.back().first++;
                if(sta.back().first == k) {
                    sta.pop_back();
                }
            } else {
                sta.push_back({1, c});
            }
        }
        string ans = "";
        for(auto c: sta) {
            if(c.second != '#') {
                ans.append(c.first, c.second);
            }
        }
        return ans;
    }
};