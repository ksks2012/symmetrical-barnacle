#include "include.h"

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(auto i : gifts) {
            pq.push(i);
        }

        while (!pq.empty() && pq.top() != 1 && k > 0) {
            int tmp = pq.top();
            pq.pop();
            pq.push(int(sqrt(tmp)));
            k--;
        }

        int res = 0;

        while(!pq.empty()) {
            res += pq.top();
            pq.pop();
        }

        return res;
    }
};