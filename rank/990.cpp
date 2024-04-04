#include "include.h"

class Solution {
public:
    int tmp[26] = {};

    bool equationsPossible(vector<string>& equations) {

        for(int i = 0; i < 26; i++) {
            tmp[i] = i;
        }

        for(auto e : equations) {
            int a = e[0] - 'a';
            int b = e[3] - 'a';
            if(e[1] == '=') {
                tmp[union_find(a)] = union_find(b);
            }
        }

        for(auto e : equations) {
            int a = e[0] - 'a';
            int b = e[3] - 'a';
            if(e[1] == '!' && union_find(a) == union_find(b)) {
                return false;
            }
        }

        return true;
    }

    int union_find(int x) {
        if (x != tmp[x]) 
            tmp[x] = union_find(tmp[x]);
        return tmp[x];
    }
};