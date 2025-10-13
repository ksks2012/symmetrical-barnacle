#include "include.h"

class Solution {
public:
    bool checkBalanced(int count[]) {
        int num = 0;
        for(int i = 0; i < 26; i++) {
            if(count[i] != 0) {
                if(num == 0) {
                    num = count[i];
                } else if(num != count[i]) {
                    return false;
                }
            }
        }
        return true;
    }

    int longestBalanced(string s) {
        int left = 0;
        int right = 0;
        int n = s.size();
        int res = 0;

        for(int i = 0; i < n; i++) {
            int count[26] = {0};
            for(int j = i; j < n; j++) {
                count[s[j] - 'a']++;
                if(checkBalanced(count)) {
                    res = max(res, j - i + 1);
                }
            }
        }
        
        return res;
    }
};