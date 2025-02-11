#include "include.h"

class Solution {
public:
    int maxVowels(string s, int k) {
        int res = 0;
        int tmp = 0;
        unordered_set<char> bag = {'a', 'e', 'i', 'o', 'u'};
        int left = 0;
        for(int right = 0; right < s.size(); right++) {
            tmp += bag.count(s[right]);
            if(right - k >= 0) {
                tmp -= bag.count(s[left++]);
            }
            res = max(res, tmp);
        }
        return res;
    }
};