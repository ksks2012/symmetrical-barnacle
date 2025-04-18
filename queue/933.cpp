#include "include.h"

class RecentCounter {
public:
    
    queue<int> q; 
        
    RecentCounter() {
        
    }
    
    int ping(int t) {
        if(q.size() == 0) {
            q.push(t);
            return q.size();
        }
            
        while(t - q.front() > 3000 && q.size() != 0) {
            q.pop();
        }
        
        q.push(t);
        
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */