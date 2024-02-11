#include "include.h"

class Solution {
public:
    int helper(string s) {
        char ch = s[0];
        for(int i = 1; i < s.size(); i++) {
            ch = min(ch, s[i]);
        }
        
        int count = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ch) {
                count++;
            }
        }
        return count;        
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int m = queries.size();
        vector<int> q(m, 0);
        for(int i = 0; i < m; i++) {
            q[i] = helper(queries[i]);
        }

        int n = words.size();
        vector<int> w(n, 0);
        for(int i = 0; i < n; i++) {
            w[i] = helper(words[i]);
        }

        sort(w.begin(), w.end());
        vector<int> ans(m, 0);
        for(int i = 0; i < m; i++) {
            ans[i] = n - (upper_bound(w.begin(), w.end(), q[i]) - w.begin());
        }

        return ans;
    }   
};