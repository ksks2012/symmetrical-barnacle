#include "include.h"

class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        int s_one = 0;
        int t_one = 0;
        for(int i = 0; i < s.size(); i++){
            s_one += s[i] == '1';
            t_one += target[i] == '1';
        }
        return s_one > 0 == t_one > 0;
    }
};