#include "../include.h"

const int INF = 1e9;

class Solution {
public: 
    int n, tmp1[1005], tmp2[1005];
    // not swapped
    int status1() {
        int c = 0;
        for (int i = 1; i < n; i++) {
            if (tmp1[i] <= tmp1[n] && tmp2[i] <= tmp2[n]) {

            } else if (tmp2[i] <= tmp1[n] && tmp1[i] <= tmp2[n]) {
                c++;
            } else {
                return INF;
            }
        }
        return c;
    }

    // swapped
    int status2() {
        int count = 1;
        swap(tmp1[n], tmp2[n]);
        for (int i = 1; i < n; i++) {
            if (tmp1[i] <= tmp1[n] && tmp2[i] <= tmp2[n]) {

            } else if (tmp2[i] <= tmp1[n] && tmp1[i] <= tmp2[n]) {
                count++;
            } else {
                return INF;
            }
        }
        return count;
    }
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        for (int i = 1; i <= n; i++) 
            tmp1[i] = nums1[i - 1], tmp2[i] = nums2[i - 1];
        int ans = min(status1(), status2());
        if (ans == INF) ans = -1;
        return ans;
    }
};