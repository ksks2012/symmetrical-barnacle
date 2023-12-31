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