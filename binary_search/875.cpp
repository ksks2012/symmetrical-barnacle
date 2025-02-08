#include "include.h"

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        
        while (left < right) {
            int mid = (left + right) / 2;
            if (helper(piles, mid, h)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
    
private:
    bool helper(vector<int>& piles, int speed, int h) {
        int time = 0;
        for (int pile : piles) {
            time += (pile - 1) / speed + 1;
            if (time > h) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());

        while(left < right) {
            int mid = (left + right) / 2;
            int cur = 0;
            for(int i = 0; i < piles.size(); i++) {
                if(cur > h) {
                    break;
                }
                cur += (piles[i] - 1) / mid + 1;
            }
            if(cur > h) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return right;
    }
};