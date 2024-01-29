#include "include.h"

class Solution {
public:
    int arrangeCoins(int n) {
        int rows = 1;
        while(n > 0) {     
            rows++;        
            n -= rows;     
        }
        return rows - 1;  
    }
};

// Solution
class Solution {
public:
    int arrangeCoins(int n) {
        int left = 1, right = n, ans;
		long rows, coinsNeeded;
        while(left <= right) {
            rows = left + ((right - left) >> 1);                    // finding mid of range [l, r]
            coinsNeeded = (rows * (rows + 1)) >> 1;                 // coins needed for 'rows' number of row
            if(coinsNeeded <= n) 
                left = rows + 1, ans = rows;                        // if available coins are sufficient
            else 
                right = rows - 1;                                   // coins insufficient, eliminate the half greater than rows
        }
        return ans;
    }
};