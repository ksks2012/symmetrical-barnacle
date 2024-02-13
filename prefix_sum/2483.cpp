#include "include.h"

class Solution {
public:
    int bestClosingTime(string customers) {
        int ans = -1;
        int n = customers.size();
        
        int tmp = 0;
        int maxi = 0;
        for(int i = 0; i < n; i++) {
            if(customers[i] == 'Y') {
                tmp += 1;
            } else {
                tmp -= 1;
            }
            if(tmp > maxi) {
                ans = i;
                maxi = tmp;
            }
        }

        return ans + 1;   
    }
};