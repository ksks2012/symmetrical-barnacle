#include "include.h"

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());

        long long res = 0;
        while (k--) {
            int tmp = pq.top();
            res += tmp;
            pq.pop();
            pq.push(ceil(tmp / 3.0));
        }

        return res;
    }
};