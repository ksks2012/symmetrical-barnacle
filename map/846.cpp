#include "../include.h"

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0)
            return false;
        map<int, int> mp;

        for(int i = 0; i < n; i++) {
            mp[hand[i]]++;
        }

        for(auto it = mp.begin(); it != mp.end(); it++) {
            if(it->second == 0)
                continue;
            int cnt = it->second;
            for(int i = 1; i < groupSize; i++) {
                if(mp[it->first + i] < cnt)
                    return false;
                mp[it->first + i] -= cnt;
            }
        }

        return true;   
    }
};

// lee
class Solution {
public:
    bool isNStraightHand(vector<int> hand, int groupSize) {
        map<int, int> mp;
        for (int i : hand) 
            mp[i]++;
            
        for (auto it : mp)
            if (mp[it.first] > 0)
                for (int i = groupSize - 1; i >= 0; --i)
                    if ((mp[it.first + i] -= mp[it.first]) < 0)
                        return false;
        return true;
    }
};