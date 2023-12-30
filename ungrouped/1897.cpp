#include "include.h"

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> hash(26, 0);

        int n = words.size();
        for(auto w : words) {
            for(auto c: w) {
                hash[c - 'a']++;
            }
        }       

        for(int i = 0; i < 26; i++) {
            if(hash[i] % n != 0)
                return false;
        }
        return true;
    }
};