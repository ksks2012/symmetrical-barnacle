#include "include.h"

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        for(int i = 0; i < answers.size(); i++) {
            mp[answers[i]]++;
        }
        int res = 0;
        for(auto p : mp) {
            if(p.first == 0) {
                res += p.second;
            } else if(p.second > (p.first + 1)) {
                int pairs = p.second / (p.first + 1);
                int solo = p.second % (p.first + 1);
                if(solo <= p.first + 1 && solo != 0) {
                    solo = 1;
                }
                res += (p.first + 1) * (pairs + solo);
            } else {
                res += (p.first + 1);
            }
        }
        return res;        
    }
};