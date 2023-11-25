#include "../include.h"

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        // sort bars
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        
        int answer = 0, h_removed = 0;
            
        for(int h = 0; h < hBars.size(); h++) {
            // if: consecutive horizontal bars are appears then add 1 bar into horizontal removed bar(h_removed++) 
            // else: set h_removed = 1
            if(h && hBars[h - 1] == hBars[h] - 1) 
                h_removed++;
            else 
                h_removed = 1;
            
            int v_removed = 0;
            
            for(int v = 0; v < vBars.size(); v++) {
                // if: consecutive vertical bars are appears then add 1 bar into vertical removed bar(v_removed++) 
                // else: set v_removed = 1
                if(v && vBars[v - 1] == vBars[v] - 1) 
                    v_removed++;
                else 
                    v_removed = 1;
                
                // here min used for calculating equal width and height length
                int width = min(h_removed + 1, v_removed + 1);
                
                answer = max(answer,  width * width);
            }
        }
        
        return answer;
    }
};