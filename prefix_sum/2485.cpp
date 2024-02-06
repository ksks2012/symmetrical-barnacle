#include "include.h"

class Solution {
public:
    int pivotInteger(int n) {
        vector<int> sum(n + 2, 0);
        int tmp = 0;
        for(int i = 0; i <= n; i++) {
            tmp += i;
            sum[i + 1] = tmp;
        }

        for(int i = 0; i <= n; i++) {
            if((sum[i + 1] - sum[0]) == (sum[n + 1] - sum[i])) {
                return i;
            }
        }

        return -1;
    }
};

// With binary search
class Solution {
public:
    int pivotInteger(int n) {
        vector<int> sum(n + 2, 0);
        int tmp = 0;
        for(int i = 0; i <= n; i++) {
            tmp += i;
            sum[i + 1] = tmp;
        }

        int left = 0;
        int right = n;

        while(left <= right) {
            int mid = left + (right - left) / 2;
            if((sum[mid + 1] - sum[0]) == (sum[n + 1] - sum[mid])) {
                return mid;
            } else if((sum[mid + 1] - sum[0]) < (sum[n + 1] - sum[mid])) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
};