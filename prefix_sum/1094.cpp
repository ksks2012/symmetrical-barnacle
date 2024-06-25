#include "../include.h"

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> tmp(1001, 0);

        for(int i = 0; i < trips.size(); i++) {
            tmp[trips[i][1]] += trips[i][0];
            tmp[trips[i][2]] -= trips[i][0];
        }

        for(int i = 0; capacity >= 0 && i < tmp.size(); i++) {
            capacity -= tmp[i];
        }

        return capacity >= 0;
    }
};

class Solution {
public:
    
    static bool comp(vector<int> left, vector<int> right) {
        if(left[1] < right[1] || (left[1] == right[1] && left[2] < right[2]))
            return true;
        return false;
    }
        
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
		
        sort(trips.begin(), trips.end(),comp);
        
        int curr = 0;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // destinaton , numpassengers
        
        for(int i = 0; i < n; i++) {
			// step 1 
            while(!pq.empty() && pq.top().first <= trips[i][1]) {
                curr -= pq.top().second;
                pq.pop();
            }
            
			// step 2
            pq.push({trips[i][2], trips[i][0]});
            curr += trips[i][0];
			
			//step 3
            if(curr > capacity)
                return false;
        }
		
        return true;  
    }
};