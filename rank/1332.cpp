#include "include.h"

// lee
class Solution {
public:
    int removePalindromeSub(string s) {
        return 2 - (s == string(s.rbegin(), s.rend())) - s.empty();
    }
};

class Solution {
public:
    int removePalindromeSub(string s) {
        int left = 0, right = s.size() - 1;
        while(left < right) {
            if(s[left] != s[right]) 
                return 2;
            left++;
            right--;
        }
        
        return 1;
    }
};