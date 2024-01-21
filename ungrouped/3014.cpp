#include "include.h"

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        unordered_map<char, int> m;
        for(int i = 0; i < n; i++) {
            m[word[i]]++;
        }

        int ans = 0;
        vector<int> tmp;
        for(auto i : m) {
            tmp.push_back(i.second);
        }

        sort(tmp.begin(), tmp.end());
        reverse(tmp.begin(), tmp.end());
        for(int i = 0; i < tmp.size(); i++) {
            ans += tmp[i] * (i / 8 + 1);
        }

        return ans;
    }
};