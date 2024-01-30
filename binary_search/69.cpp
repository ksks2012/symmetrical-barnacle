#include "../include.h"

class Solution {
public:
    int mySqrt(int x) {
        return (int) sqrt(x);      
    }
};


class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = INT_MAX;

        while(left < right) {
            int mid = left + (right - left) / 2;
            if(mid > x / mid) {
                right = mid - 1;
            } else {
                if(mid + 1 > x / (mid + 1))
                    return mid;
                left = mid + 1;
            }
        }
        return left;
    }
};


