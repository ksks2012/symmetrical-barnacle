#include "include.h"

class Solution {
public:
    
    int conversion(int num){
        int res = 0;
        while(num > 0) {
            res += num % 10;
            num /= 10;
        }
        return res; 
    }
    
    int maximumSum(vector<int>& nums) {
        // digit , two max nums[i]
        unordered_map<int, pair<int, int>> m; 
        int maxi = -1;
        
        for(auto it : nums) {
            int tmp = conversion(it);
            
            if(m.find(tmp) != m.end()) {
                if(it > m[tmp].first) {
                    m[tmp].second = m[tmp].first;
                    m[tmp].first = it;
                } else if(it > m[tmp].second) {
                    m[tmp].second = it;
                }

                if(m[tmp].second != -1) {
                    int ans = m[tmp].first + m[tmp].second;
                    maxi = max(maxi, ans);
                }
            } else {
                m[tmp] = make_pair(it, -1);
            }
        }
        return maxi;
    }
};