#include "include.h"

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int ans = 0;

        while(left < right) {
            int tmp = (right - left) * min(height[left], height[right]);
            if(tmp > ans)
                ans = tmp;
            if(height[left] > height[right])
                right--;
            else
                left++;
        }
        return ans;
    }
};