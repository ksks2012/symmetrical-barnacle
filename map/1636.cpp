#include "include.h"

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        vector<pair<int, int>> freqVec(freq.begin(), freq.end());
        sort(freqVec.begin(), freqVec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second == b.second) {
                return a.first > b.first; // Sort by value in descending order
            }
            return a.second < b.second; // Sort by frequency in ascending order
        });

        vector<int> res;
        for (const auto& p : freqVec) {
            res.insert(res.end(), p.second, p.first);
        }

        return res;        
    }
};