#include "../include.h"

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int, int>> q; // <index, tickets>
        for (int i = 0; i < tickets.size(); ++i) {
            q.push({i, tickets[i]});
        }

        int res = 0;

        while (!q.empty()) {
            auto [index, count] = q.front();
            q.pop();

            if (count > 0) {
                res++;
                count--;
                if (index == k && count == 0) {
                    break;
                }
                if (count > 0) {
                    q.push({index, count});
                }
            }
        }

        return res;
    }
};