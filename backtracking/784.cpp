#include "include.h"

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        backtracking(s, ans, 0, "");
        return ans;
    }

    void backtracking(string s, vector<string> &ans, int cur_idx, string cur) {
        if(cur_idx == s.length()) {
            ans.push_back(cur);
            return;
        }

        if('0' <= s[cur_idx] && s[cur_idx] <= '9') {
            backtracking(s, ans, cur_idx + 1, cur + s[cur_idx]);
        } else if ('a' <= s[cur_idx] && s[cur_idx] <= 'z') {
            backtracking(s, ans, cur_idx + 1, cur + s[cur_idx]);
            char tmp = (s[cur_idx] - 32);
            backtracking(s, ans, cur_idx + 1, cur + tmp);
        } else if ('A' <= s[cur_idx] && s[cur_idx] <= 'Z') {
            backtracking(s, ans, cur_idx + 1, cur + s[cur_idx]);
            char tmp = (s[cur_idx] + 32);
            backtracking(s, ans, cur_idx + 1, cur + tmp);
        }
    }
};