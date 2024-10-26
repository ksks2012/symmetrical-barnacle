#include "include.h"

class Solution {
public:
    string customSortString(string order, string s) {
        int n = s.size();
        int m = order.size();
        vector<int> cnt(26, 0);
        for(int i = 0; i < n; i++) {
            cnt[s[i] - 'a']++;
        }
        string res = "";
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < cnt[order[i] - 'a']; j++) {
                res += order[i];
            }
        }
        for(int i = 0; i < 26; i++) {
            if(order.find('a' + i) == string::npos) {
                for(int j = 0; j < cnt[i]; j++) {
                    res += 'a' + i;
                }
            }
        }
        return res;        
    }
};