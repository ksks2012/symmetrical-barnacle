#include "include.h"

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int res = 0;
        
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                pq.push(nums[i]);
            }
        }


        while(!pq.empty()) {
            int mini = pq.top();
            res++;
            priority_queue<int, vector<int>, greater<int>> pq_tmp;
            while(!pq.empty()) {
                int tmp = pq.top() - mini;
                pq.pop();
                if(tmp != 0) {
                    pq_tmp.push(tmp);
                }
            }
            pq = pq_tmp;
        }

        return res;
    }
};