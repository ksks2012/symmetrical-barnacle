#include "include.h"

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;

        for(auto p: piles) {
            pq.push(p);
        }

        for(int i = 0; i < k; i++) {
            int tmp = pq.top();
            pq.pop();
            tmp -= floor((double)tmp / 2);
            pq.push(tmp);
        }
        
        int res = 0;
        while(!pq.empty()) {
            res += pq.top();
            pq.pop();
        }

        return res;
    }
};

// lee
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());
        // prefix sum
        int res = accumulate(piles.begin(), piles.end(), 0);
        while (k--) {
            int tmp = pq.top();
            pq.pop();
            int diff = tmp / 2;
            pq.push(tmp - diff);
            res -= diff;
        }
        return res;
    }
};