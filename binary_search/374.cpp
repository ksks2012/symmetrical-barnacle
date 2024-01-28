#include "../include.h"

int guess(int num) {
    return 0;
}

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 0;
        int right = n - 1;

        int result = -2;
        while(result != 0) {
            int mid = left + (right - left) / 2;
            result = guess(mid);
            if(result == 0) {
                return mid;
            } else if(result == 1) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return 0;
    }
};