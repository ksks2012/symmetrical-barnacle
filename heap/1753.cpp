#include "include.h"

// Heap
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int res = 0;

        priority_queue<int> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);

        while(pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if(x > 1) {
                pq.push(x - 1);
            }
            if(y > 1) {
                pq.push(y - 1);
            }
            res++;
        }

        return res;
    }
};

// votrubac
// recursive
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        if (a < b)
            return maximumScore(b, a, c);
        if (b < c)
            return maximumScore(a, c, b);
        return b == 0 ? 0 : 1 + maximumScore(a - 1, b - 1, c); 
    }
};

// Math
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        return min((a + b + c) / 2, a + b + c - max({a, b, c}));
    }
};