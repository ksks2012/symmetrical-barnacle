#include "../include.h"

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        long long mod= 1e9 + 7;
        
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);



        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_map<int, int> tmp;
        for(int i = 0; i < hFences.size(); i++) {
            for(int j = i + 1; j < hFences.size(); j++) {
                tmp[hFences[j] - hFences[i]] = 0;
            }
        }
        long long max_ans = -1;
        for(int i = 0; i < vFences.size(); i++) {
            for(int j = i + 1; j < vFences.size(); j++) {
                if(tmp.find(vFences[j] - vFences[i]) != tmp.end()) {
                    max_ans = max((long long)vFences[j] - vFences[i], max_ans);
                }
            }
        }
        if(max_ans == -1)
            return -1;

        return max_ans * max_ans % mod;
    }
};
