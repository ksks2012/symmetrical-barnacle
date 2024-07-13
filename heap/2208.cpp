#include "include.h"

class Solution {
public:

    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;

        double sum = 0;

        for(auto ele : nums) {
            sum += ele;
            pq.push(ele);
        }
        
        double half = sum / 2;

        int res = 0;
        while(sum > half) { 
            double maxi = pq.top();
            pq.pop();

            maxi /= 2;
            pq.push(maxi);          
            res++;

            sum -= maxi; 
        }
       
        return res;
        
    }
};