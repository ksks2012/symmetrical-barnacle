#include "include.h"

#define MOD 1000000007
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<int, long long> m;
        for(int i = 0; i < n; i++) {
            m[arr[i]]++;
        }

        long long ans = 0;
        for(auto v1: m) {
            for(auto v2: m) {
                int i = v1.first;
                int j = v2.first;
                int k = target - i - j;
                if(!m.count(k)) {
                    continue;
                }
                if(i == j && j == k) {
                    ans = (ans + m[i] * (m[i] - 1) * (m[i] - 2) / 6) % MOD;
                } else if(i == j && j != k) {
                    ans = (ans + m[i] * (m[i] - 1) / 2 * m[k]) % MOD;
                } else if(i < j && j < k) {
                    ans = (ans + m[i] * m[j] * m[k]) % MOD;
                }
            }
        }
        return ans;
    }
};