#include "include.h"

class MyCalendarThree {
public:
    map<int, int> tmp;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        tmp[startTime]++; // 1 new event will be starting at [s]
        tmp[endTime]--; // 1 new event will be ending at [e];
        int ongoing = 0, k = 0;
        for (pair<int, int> t : tmp)
            k = max(k, ongoing += t.second);
        return k;  
    }
};
    
/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */