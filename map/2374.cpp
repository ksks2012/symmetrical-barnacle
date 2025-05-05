#include "include.h"

class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> score(n, 0);
        for (int i = 0; i < n; ++i) {
            score[edges[i]] += i;
        }
        long long maxScore = 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (score[i] > maxScore) {
                maxScore = score[i];
                res = i;
            }
        }
        return res;        
    }
};