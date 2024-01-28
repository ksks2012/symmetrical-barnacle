#include "../include.h"

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();        
        int left = 0;
        int right = n;

        while(left < right) {
            int mid = left + (right - left) / 2;
            if(target < letters[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return letters[left % n];
    }
};