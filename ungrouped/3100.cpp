#include "include.h"

class Solution {
public:
    int DFS(int numBottles, int emptyBottles, int numExchange) {
        if(numBottles == 0 && emptyBottles < numExchange) {
            return 0;
        }

        int res = 0;
        if(numBottles > 0) {
            res = max(res, DFS(0, emptyBottles + numBottles, numExchange)+ numBottles);
        }

        if(emptyBottles >= numExchange) {
            res = max(res, DFS(numBottles + 1, emptyBottles - numExchange, numExchange + 1));
        }

        return res;
    }

    int maxBottlesDrunk(int numBottles, int numExchange) {
        return DFS(numBottles, 0, numExchange);
    }
};