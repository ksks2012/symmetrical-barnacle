#include "include.h"

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<string> ans;
        int n = s.length();

        int cur = 0;
        int left = 0;
        int mini = INT_MAX;

        for(int i = 0; i < n; i++) {
            k -= s[i] == '1';
            while(k < 0 || s[left] == '0') {
                k += s[left++] == '1';
            }
            if(k == 0) {
                ans.push_back(s.substr(left, i - left + 1));
                mini = min(mini, i - left + 1);
            }
        }

        sort(ans.begin(), ans.end());
        for(auto t : ans) {
            if(t.size() == mini)
                return t;
        }

        return "";
    }
};

// Optimization
class Solution {
public:
    string shortestBeautifulSubstring(const string &s, int k) {
        int res_right = s.size() - 1, res_left = 0;
        for (int i = 0, j = 0; i < s.size(); ++i) {
            k -= s[i] == '1';
            while (k < 0 || s[j] == '0')
                k += s[j++] == '1';
            if (k == 0 && res_right - res_left >= i - j)
                if (res_right - res_left > i - j || (res_right - res_left == i - j && 
                    s.compare(j, i - j + 1, s, res_left, res_right - res_left + 1) < 0)) {
                    res_right = i;
                    res_left = j;
                }
        }
        return k == 0 ? s.substr(res_left, res_right - res_left + 1) : "";
    }
};
