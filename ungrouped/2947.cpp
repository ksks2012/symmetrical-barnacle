#include "../include.h"

class Solution {
public:
    void bc(string &s, int &ans, int k, int v, int c, int cur, string cur_str) {
        
        if(v != 0 && c != 0 && v == c && (v * c) % k == 0) {
            ans++;
        }
        if(cur == s.size())
            return;
            
        for(int j = cur; j < s.size(); j++) {
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
                bc(s, ans, k, v + 1, c, j + 1, cur_str + s[j]);
            else
                bc(s, ans, k, v, c + 1, j + 1, cur_str + s[j]);
        }
    }

    int beautifulSubstrings(string s, int k) {
        int vowels = 0;
        int consonants = 0;

        int ans = 0;
        bc(s, ans, k, 0, 0, 0, "");
        
        return ans;
    }
};

class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            int v = 0;
            int c = 0;
            for(int j = i; j < s.size(); j++) {
                if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
                    v++;
                else
                    c++;
                if(v != 0 && c != 0 && v == c && (v * c) % k == 0) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};