#include "include.h"

// fast IO
static auto __ = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    string lastNonEmptyString(string s) {
        string tmp_s = "";
        while(s.size() != 0) {
            int tmp[26] = {0};
            tmp_s = "";
            for(int i = 0; i < s.size(); i++) {
                if(tmp[s[i] - 'a'] != 0) {
                    tmp_s += s[i];
                } else {
                    tmp[s[i] - 'a'] = 1;
                }
            }
            if(tmp_s.size() == 0) {
                break;
            }
            s = tmp_s;
        }

        return s;
    }
};

class Solution {
public:
    string lastNonEmptyString(string s) {
        int tmp[26] = {0};

        for(int i = 0; i < s.size(); i++) {
            tmp[s[i] - 'a']++;
        }

        int maxi = 0;
        for(int i = 0; i < 26; i++) {
            maxi = max(maxi, tmp[i]);
        }

        for(int i = 0; i < 26; i++) {
            tmp[i] -= (maxi - 1);
        }
    
        string ans = "";
        for(int i = s.size() - 1; i >= 0; i--) {
            if(tmp[s[i] - 'a'] == 1) {
                ans = s[i] + ans;
                tmp[s[i] - 'a']--;
            }
        }

        return ans;
    }
};
