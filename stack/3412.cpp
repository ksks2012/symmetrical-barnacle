#include "include.h"

class Solution {
public:
    long long calculateScore(string s) {
        stack<int> st[26];
        long long res = 0;
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            if (!st[25 - c].empty()) {
                res += i - st[25 - c].top();
                st[25 - c].pop();
            } else {
                st[c].push(i);                
            }
        }
        return res;
    }
};