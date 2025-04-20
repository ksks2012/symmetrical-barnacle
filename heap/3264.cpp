#include "include.h"

class Solution {
public:
    static vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        const int n=nums.size();
        for(int i=0; i<n; i++){
            pq.emplace(nums[i],i);
        }
        for(int i=0; i<k; i++){
            auto  [x, j]=pq.top();
            pq.pop();
            pq.emplace(multiplier*x, j);
        }
        while(!pq.empty()){
            auto [x,i]=pq.top();
            pq.pop();
            nums[i]=x;
        }
        return nums;
    }
};