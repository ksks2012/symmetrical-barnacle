#include "include.h"

// 2970.
// endlesscheng
class Solution {
public:
    int incremovableSubarrayCount(vector<int> &a) {
        int n = a.size();
        int i = 0;
        while (i < n - 1 && a[i] < a[i + 1]) {
            i++;
        }
        // remove not null
        if (i == n - 1) {
            return n * (n + 1) / 2;
        }

        int ans = i + 2;
        for (int j = n - 1; j == n - 1 || a[j] < a[j + 1]; j--) {
            while (i >= 0 && a[i] >= a[j]) {
                i--;
            }
            ans += i + 2;
        }
        return ans;
    }
};
