#include "include.h"

class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        int ans = 0;
        long long cur_sum = 0;

        for(auto coin : coins) {
            while(cur_sum + 1 < coin) {
                cur_sum += cur_sum + 1;
                ans++;
                if(cur_sum >= target)
                    return ans;
            }
            cur_sum += coin;
            cout << cur_sum << endl;
        }
        while(cur_sum < target) {
            cur_sum += cur_sum + 1;
            ans++;
        }
        return ans;
    }
};