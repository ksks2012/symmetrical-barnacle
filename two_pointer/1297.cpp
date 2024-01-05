#include "include.h"

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int count[26] = {0};
        int n = s.length();
        unordered_map<string, int> m;
        int left = 0;
        int unique = 0;
        for(int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
            if(count[s[i] - 'a'] == 1)
                unique++;
            while(unique > maxLetters || i - left + 1 > minSize) {
                count[s[left] - 'a']--;
                if(count[s[left] - 'a'] == 0)
                    unique--;
                left++;
            }
            if(i - left + 1 == minSize) {
                m[s.substr(left, i - left + 1)]++;
            }
        }   

        int ans = 0;

        for(auto v: m) {
            ans = max(v.second, ans);
        }

        return ans;
    }
};