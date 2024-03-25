#include "include.h"

class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        set<int> s(nums.begin(), nums.end());
        for(int i = 0; i < moveFrom.size(); i++) {
            s.erase(moveFrom.at(i));
            s.insert(moveTo.at(i));
        }
        
        return vector<int> (s.begin(), s.end());;
    }
};