#include "include.h"

class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq(amount.begin(), amount.end()); 
    
        int res = 0;
        while (pq.top() > 0) {
            int first = pq.top(); pq.pop();
            int second = pq.top(); pq.pop();
            first--;
            second--;
            pq.push(first);
            pq.push(second);
            res++;
        }
    
        return res;
    }
};