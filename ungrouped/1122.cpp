#include "include.h"

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;
        for (int num : arr1) {
            mp[num]++;
        }

        vector<int> result;
        for (int num : arr2) {
            if (mp.find(num) != mp.end()) {
                result.insert(result.end(), mp[num], num);
                mp.erase(num);
            }
        }

        vector<int> remaining;
        for (const auto& entry : mp) {
            remaining.insert(remaining.end(), entry.second, entry.first);
        }
        
        sort(remaining.begin(), remaining.end());
        result.insert(result.end(), remaining.begin(), remaining.end());

        return result;   
    }
};