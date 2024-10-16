#include "include.h"

typedef pair<int, char> PIC;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<PIC> pq;
        // Add the counts of a, b and c in priority queue.
        if (a > 0) {
            pq.push({a, 'a'});
        }

        if (b > 0) {
            pq.push({b, 'b'});
        }

        if (c > 0) {
            pq.push({c, 'c'});
        }

        string res = "";
        while (!pq.empty()) {
            PIC p = pq.top();
            pq.pop();
            int count = p.first;
            char tmp = p.second;
            // If three consecutive characters exist, pick the second most
            // frequent character.
            if (res.length() >= 2 and res[res.length() - 1] == p.second and
                res[res.length() - 2] == p.second) {
                if (pq.empty()) 
                    break;

                PIC temp = pq.top();
                pq.pop();
                res += temp.second;
                if (temp.first - 1 > 0) {
                    pq.push({temp.first - 1, temp.second});
                }
            } else {
                count--;
                res = res + tmp;
            }

            // If count is greater than zero, add it to priority queue.
            if (count > 0) {
                pq.push({count, tmp});
            }
        }
        return res;
    }
};