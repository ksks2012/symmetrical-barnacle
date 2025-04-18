#include "include.h"

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> q_r, q_d;
        int n = senate.length();

        for(int i = 0; i < n; i++)
            (senate[i] == 'R') ? q_r.push(i) : q_d.push(i);

        while(!q_r.empty() && !q_d.empty()){
            int r_id = q_r.front(), d_id = q_d.front();
            q_r.pop(), q_d.pop();
            (r_id < d_id) ? q_r.push(r_id + n) : q_d.push(d_id + n);
        }
        
        return (q_r.size() > q_d.size()) ? "Radiant" : "Dire";
    }
};