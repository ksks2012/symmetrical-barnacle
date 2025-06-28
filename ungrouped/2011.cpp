#include "../include.h"

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res = 0;
        for (const auto& op : operations) {
            if (op == "++X" || op == "X++") {
                res++;
            } else if (op == "--X" || op == "X--") {
                res--;
            }
        }
        return res;
    }
};