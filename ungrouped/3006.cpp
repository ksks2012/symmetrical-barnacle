#include "include.h"

class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b_size, int k) {
        // Vector to store the beautiful indices
        vector<int> ans, indices_a, indices_b;
        
        // Lengths of strings
        int s_size = s.size(), a_size = a.size(), z = b_size.size();
        
        // Step 2: Find indices of occurrences of string 'a'
        for (int i = 0; i <= s_size - a_size; i++) {
            if (s.substr(i, a_size) == a) {
                indices_a.push_back(i);
            }
        }
        
        // Step 3: Find indices of occurrences of string 'b'
        for (int j = 0; j <= s_size - z; j++) {
            if (s.substr(j, z) == b_size) {
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