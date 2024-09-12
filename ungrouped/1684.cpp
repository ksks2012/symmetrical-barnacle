#include "include.h"

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int arr[26] = {0};
        for (char c : allowed) {
            arr[c - 'a'] = 1;
        }
        
        int res = 0;
        for (string word : words) {
            int flag = 1;
            for (char c : word) {
                if (arr[c - 'a'] == 0) {
                    flag = 0;
                    break;
                }
            }
            res += flag;
        }
        return res;
    }
};