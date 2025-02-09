#include "include.h"

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left = 0;
        int right = citations.size();
        
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(citations[mid] >= citations.size() - mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return citations.size() - left;
    }
};