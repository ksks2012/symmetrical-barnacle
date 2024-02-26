#include "include.h"

class Solution {
public:
    vector<int> vec;
    vector<int> dis;
    
    Solution(vector<int>& w) {
        dis = w;
        
        int sum = 0;
        for(auto &v : dis) {
            sum += v;
            v = sum;
        }
        
    }
    
    int pickIndex() {
        
        int randN = rand() % dis[dis.size() - 1];

        auto low = upper_bound(dis.begin(), dis.end(), randN);
    
        return distance(dis.begin(), low);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */