#include "include.h"

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int count[26] = {0};
        int n = s.length();
        unordered_map<string, int> m;
        int left = 0;
        // how much char in substring
        int unique = 0;
        for(int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
            // right pointer have new char
            if(count[s[i] - 'a'] == 1)
                unique++;
            // substring has too much char or longer then min size
            while(unique > maxLetters || i - left + 1 > minSize) {
                count[s[left] - 'a']--;
                // left pointer delete unique char
                if(count[s[left] - 'a'] == 0)
                    unique--;
                left++;
            }
            // Only consider min size of substring cause we are finding maximum number
            // Save legal substring 
            if(i - left + 1 == minSize) {
                m[s.substr(left, i - left + 1)]++;
            }
        }   

        int ans = 0;

        // Find maximum number
        for(auto v: m) {
            ans = max(v.second, ans);
        }

        return ans;
    }
};