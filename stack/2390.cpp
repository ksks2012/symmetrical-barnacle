#include "include.h"

class Solution {
public:
    string removeStars(string s) {
        stack<char> tmp;

        string res = "";
        for (auto&& i : s) {
            if (i == '*') {
                if (!tmp.empty())
                    tmp.pop();
            } else {
                tmp.push(i);
            }
        }

        while (!tmp.empty()) {
            res += tmp.top();
            tmp.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};