#include "include.h"

// Aditya
class Solution {
    long long pie(vector<int> &coins, long long x) {
        int m = coins.size();
        int nn = (1 << m);
        long long cnt = 0;
        for (int i = 1; i < nn; i++) {
            long long lcmm = 1;
            for (int j = 0; j < m; j++) {
                if (i & (1 << j)) {
                    lcmm = lcm(lcmm, coins[j]);
                }
            }
            if (__builtin_popcount(i) & 1)
                cnt += x / lcmm;
            else
                cnt -= x / lcmm;
        }
        return cnt;
    }

public:
    long long findKthSmallest(vector<int> &coins, int k) {
        long long kk = k;
        long long l = 1, r = 1e11, ans = 0;
        while (l <= r) {
            long long m = l + (r - l) / 2;
            long long cnt = 0;
            cnt = pie(coins, m);
            if (cnt < kk)
                l = m + 1;
            else {
                ans = m;
                r = m - 1;
            }
        }
        return ans;
    }
};

class Solution {
    int gcd(int x, int y) {
        return y ? gcd(y, x % y) : x;
    }
    
    long long lcm(long long x, long long y) {
        return x / gcd(x, y) * y;
    }
    
    void dfs(const vector<int> &v, long long s, int x, int ind, int num, long long &ans) {
        if (x > s) return;
        if (ind >= v.size()) {
            if (num == 0) return;
            ans += num & 1 ? (s / x) : (-s / x);
            return;
        }
        dfs(v, s, x, ind + 1, num, ans);
        dfs(v, s, lcm(x, v[ind]), ind + 1, num + 1, ans);
    }
public:
    long long findKthSmallest(vector<int>& coins, int k) {        
        long long left = k, right = static_cast<long long>(*max_element(coins.begin(), coins.end())) * k;
        while (left <= right) {
            const long long mid = (left + right) >> 1;
            long long c = 0;
            dfs(coins, mid, 1, 0, 0, c);
            if (c >= k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right + 1;
    }
};