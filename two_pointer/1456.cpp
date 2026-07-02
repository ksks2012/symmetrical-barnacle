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

class Solution {
public:
    int maxVowels(string s, int k) {
        int vowels[26] = {1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1};

        int res = 0;
        for (auto i = 0, cur_vow = 0; i < s.size(); ++i) {
            cur_vow += vowels[s[i] - 'a'];
            if (i >= k)
                cur_vow -= vowels[s[i - k] - 'a'];
            res = max(res, cur_vow);
        }
        return res;
    }
};