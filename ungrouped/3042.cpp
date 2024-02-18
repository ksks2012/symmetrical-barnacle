#include "include.h"

class Solution {
public:
    bool check(string &a, string &b) {
        int m = a.size();
        int n = b.size();
        
        return a == b.substr(0, m) && a == b.substr(n - m);
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(check(words[i], words[j])) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};