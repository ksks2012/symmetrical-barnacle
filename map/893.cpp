#include "../include.h"


class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        int n = words.size();
        unordered_set<string> tmp;
        for(int i = 0; i < n; i++) {
            string s = words[i];
            string even = "";
            string odd = "";

            for(int j = 0; j < s.size(); j++) {
                if(j % 2 == 0) {
                    even += s[j];
                } else {
                    odd += s[j];
                }
            }

            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            string res = even + odd;
            tmp.insert(res);
        }

        return tmp.size();
    }
};