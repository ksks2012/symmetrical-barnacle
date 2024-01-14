#include "include.h"

class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        // Vector to store the beautiful indices
        vector<int> ans, indices_a, indices_b;
        
        // Lengths of strings
        int x = s.size(), y = a.size(), z = b.size();
        
        // Step 2: Find indices of occurrences of string 'a'
        for (int i = 0; i <= x - y; i++) {
            if (s.substr(i, y) == a) {
                indices_a.push_back(i);
            }
        }
        
        // Step 3: Find indices of occurrences of string 'b'
        for (int j = 0; j <= x - z; j++) {
            if (s.substr(j, z) == b) {
                indices_b.push_back(j);
            }
        }
        
        // Step 4: Check conditions and add beautiful indices to 'ans'
        for (int i = 0; i < indices_a.size(); i++) {
            for (int j = 0; j < indices_b.size(); j++) {
                // Check if substrings match and absolute difference <= k
                if (abs(indices_a[i] - indices_b[j]) <= k) {
                    ans.push_back(indices_a[i]);
                    break;
                }
            }
        }
        
        // Step 5: Sort the beautiful indices in ascending order
        sort(ans.begin(), ans.end());
        
        // Step 6: Return the final result
        return ans;
    }
};