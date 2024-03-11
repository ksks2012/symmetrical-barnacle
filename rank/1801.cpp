#include "include.h"

// votrubac
#define MOD 1000000007
class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<array<int, 2>> buy, sell;
        long res = 0;
        for (auto &order : orders) {
            res += order[1];
            if (order[2])
                sell.push({-order[0], order[1]});
            else
                buy.push({order[0], order[1]});
            while (!sell.empty() && !buy.empty() && -sell.top()[0] <= buy.top()[0]) {
                auto [sell_p, sell_a] = sell.top(); sell.pop();
                auto [buy_p, buy_a] = buy.top(); buy.pop();
                auto execute = min(sell_a, buy_a);
                res -= 2 * execute;
                if (sell_a > execute)
                    sell.push({sell_p, sell_a - execute});
                if (buy_a > execute)
                    buy.push({buy_p, buy_a - execute});   
            }
        }
        return res % MOD;
    }
};