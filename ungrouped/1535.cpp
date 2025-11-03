#include "include.h"

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        if (n == 1)
            return arr[0];

        int currentWinner = arr[0];
        int currentStreak = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] > currentWinner) {
                currentWinner = arr[i];
                currentStreak = 1;
            } else {
                currentStreak++;
            }
            if (currentStreak == k) 
                return currentWinner;
        }
        return currentWinner;
    }
};