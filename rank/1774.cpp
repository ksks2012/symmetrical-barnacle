#include "include.h"

class Solution {
public:
    int DFS(vector<int>& toppingCosts, int idx, int cur_cost, int &ans, int target) {
        if (abs(ans - target) < cur_cost - target) {
            return;
        } else if (abs(ans - target) >= abs(cur_cost - target)) {
            if (abs(ans - target) > abs(cur_cost - target)) {
                ans = cur_cost;
            } else {
                ans = min(ans, cur_cost);
            }
        }
        if (idx == toppingCosts.size()) {
            return;
        }

        // if limit > 2, change to loop
        DFS(toppingCosts, idx + 1, cur_cost + toppingCosts[idx] * 2, ans, target);
        
        DFS(toppingCosts, idx + 1, cur_cost + toppingCosts[idx], ans, target);
        DFS(toppingCosts, idx + 1, cur_cost, ans, target);
    }

    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int ans = *min_element(baseCosts.begin(), baseCosts.end());

        int n = toppingCosts.size();
        for(int i = 0; i < baseCosts.size(); i++) {
            DFS(toppingCosts, 0, baseCosts[i], ans, target);
        }

        return ans;
    }
};