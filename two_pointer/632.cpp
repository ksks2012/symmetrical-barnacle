#include "include.h"

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        // pair<int, int> stores: {value, list_index}
        vector<pair<int, int>> merged;
        
        // 1. Merge all lists into one flat list with their list identity
        for (int i = 0; i < n; i++) {
            for (int num : nums[i]) {
                merged.push_back({num, i});
            }
        }
        
        // 2. Sort the merged list by value
        sort(merged.begin(), merged.end());
        
        // 3. Sliding Window variables
        vector<int> list_cnt(n, 0); // Tracks count of elements from each list in current window
        int left = 0;
        int unique_lists_in_window = 0; // Number of unique lists fully covered in window
        
        int min_range = INT_MAX;
        vector<int> res = {0, INT_MAX};
        
        // 4. Start sliding the window
        for (int right = 0; right < merged.size(); right++) {
            int right_list_idx = merged[right].second;
            
            // If this is the first element from r_list_idx in the current window
            if (list_cnt[right_list_idx] == 0) {
                unique_lists_in_window++;
            }
            list_cnt[right_list_idx]++;
            
            // When the window contains at least one element from all K lists
            while (unique_lists_in_window == n) {
                int current_range = merged[right].first - merged[left].first;
                
                // Update the minimum range found so far
                if (current_range < min_range) {
                    min_range = current_range;
                    res = {merged[left].first, merged[right].first};
                }
                
                int left_list_idx = merged[left].second;
                list_cnt[left_list_idx]--;
                // If removing this element leaves the window with 0 elements from l_list_idx
                if (list_cnt[left_list_idx] == 0) {
                    unique_lists_in_window--;
                }
                left++; // Shrink the window from the left
            }
        }
        
        return res;
    }
};