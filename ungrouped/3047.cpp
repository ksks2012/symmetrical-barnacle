#include "include.h"

// Time Complexity: O(n^2)
// Space Complexity: O(1)
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        long long area=0;
        for(int i = 0; i < nums1.size(); i++) {
            for(int j = i + 1; j < nums1.size(); j++) {
                long long minimum_x = max(nums1[i][0], nums1[j][0]);
                long long maximum_x = min(nums2[i][0], nums2[j][0]);
                long long minimum_y = max(nums1[i][1], nums1[j][1]);
                long long maximum_y = min(nums2[i][1], nums2[j][1]);
                
                // Overlap Check
                if(minimum_x < maximum_x && minimum_y < maximum_y) {
                    // Calculate edge
                    long long s = min(maximum_x - minimum_x, maximum_y - minimum_y);
                    // Calculate area
                    area = max(area, s * s);
                }
            }
        }
        return area;
    }
};