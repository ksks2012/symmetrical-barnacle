#include "../include.h"

class Solution {
public:
    int countTestedDevices(vector<int>& b) {
        int ans = 0;
        for(int i = 0; i < b.size(); i++) {
            if(b[i] > 0) {
                ans++;
                for(int j = i + 1; j < b.size(); j++) {
                    b[j]--;
                }
            }
        }      
        return ans;
    }
};