#include "../include.h"

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) 
            return -1;

        int count = 1;
        for (int i = 1; i < n; ++i) {
            if (arr[i] == arr[i - 1]) {
                count++;
            } else {
                if (count > n / 4) {
                    return arr[i - 1];
                }
                count = 1;
            }
        }

        // Check the last element
        if (count > n / 4) {
            return arr[n - 1];
        }

        return -1; // No special integer found
    }
};