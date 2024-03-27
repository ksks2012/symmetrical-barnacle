#include "include.h"

class SeatManager {
public:
    set<int> s;
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            s.insert(i);
        }
    }
    
    int reserve() {
        if(s.empty()) 
            return -1;

        int tmp = *s.begin();
        s.erase(s.begin());
        return tmp;
    }
    
    void unreserve(int seatNumber) {
        s.insert(seatNumber);
    }
};

// Optimization
class SeatManager {
public:
    set<int> s;
    int maxi = 0;
    int n = 0;
    SeatManager(int n) {
        maxi = n;
    }
    
    int reserve() {
        if(!s.empty()) {
            int tmp = *s.begin();
            s.erase(s.begin());
            return tmp;
        } else {
            n++;
            return n;
        }
    }
    
    void unreserve(int seatNumber) {
        s.insert(seatNumber);
    }
};

// version of priority_queue
class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int maxi = 0;
    int n = 0;
    SeatManager(int n) {
        maxi = n;
    }
    
    int reserve() {
        if(!pq.empty()) {
            int tmp = pq.top();
            pq.pop();
            return tmp;
        } else {
            n++;
            return n;
        }
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};


/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */