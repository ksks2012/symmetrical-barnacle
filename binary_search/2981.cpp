#include "include.h"

class Solution {
public:
    int maximumLength(string s) {
        int max_repeat = 0;
        int tmp = 1;
        int count[26] = { 0 };
        int repeat[26] = { 0 };
        count[s[0] - 'a']++;
        int max_char = 0;
        int n = s.size();
        for(int i = 1; i < n; i++) {
            count[s[i] - 'a']++;
            if(s[i] == s[i - 1]) {
                tmp++;
            } else {
                tmp = 1;
            }
            repeat[s[i] - 'a'] = max(repeat[s[i] - 'a'], tmp);
        }

        // same repeated -> find max_count
        int max_count = 0;
        for(int i = 0; i < 26; i++) {
            if(count[i] >= 3) {
                if(repeat[i] > repeat[max_char]) {
                    max_char = i;
                } else if(repeat[i] == repeat[max_char] && count[i] > count[max_char]) {
                    max_char = i;
                }
                max_count = max(max_count, count[i]);
                max_repeat = max(max_repeat, repeat[i]);
            }
        }
        if(max_repeat >= 3) {
            for(int k = max_repeat - 1; k > 0; k--) {
                int tmp = 0;
                for(int i = 0; i < n; i++) {
                    if(s[i] - 'a' == max_char) {
                        bool check = true;
                        for(int j = i; j < i + k; j++) {
                            if(s[i] != s[j]) {
                                check = false;
                                break;
                            }
                        }
                        if(check)
                            tmp++;
                    }
                }
                if(tmp >= 3)
                    return k;
            }
        }

        
        if(max_count >= 3)
            return 1;

        return -1;
    }
};

// TLE in 2982
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
    int maximumLength(string s) {
        int n = s.size();
        int repeat[26][n + 1];
        memset(repeat, 0, sizeof(repeat));

        int tmp = 1;
        for(int i = 0; i < n; i++) {
            tmp = 1;
            repeat[s[i] - 'a'][tmp]++;
            for(int j = i + 1; j < n; j++) {
                if(s[i] == s[j]) {
                    tmp++;
                } else {
                    break;
                }
                repeat[s[i] - 'a'][tmp]++;
            }    
        }

        int max_repeat = 0;
        for(int i = 0; i < 26; i++) {
            for(int j = n; j > 0; j--) {
                if(repeat[i][j] >= 3) {
                    max_repeat = max(max_repeat, j);
                }
            }
        }
        if(max_repeat != 0)
            return max_repeat;

        return -1;
    }
};

static auto __ = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int repeat[26][n + 1];
        memset(repeat, 0, sizeof(repeat));
        int tmp = 1;
        repeat[s[0] - 'a'][tmp]++;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i - 1]) {
                tmp++;
            } else {
                tmp = 1;
            }
            repeat[s[i] - 'a'][tmp]++;
        }

        int ans = -1;
        for(int i = 0; i < 26; i++) {
            int preSum = 0;
            for(int j = n; j > 0; j--) {
                preSum += repeat[i][j];
                if(preSum >= 3) {
                    ans = max(ans, j);
                    break;
                }
            }
        }
        return ans;
    }
};