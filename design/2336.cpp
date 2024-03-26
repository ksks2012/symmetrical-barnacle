#include "../include.h"

class SmallestInfiniteSet {
public:
    int count = 1;
    set<int> s;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        int tmp = 0;
        if(!s.empty()) {
            tmp = *s.begin();
            s.erase(s.begin());
        } else {
            tmp = count++;
        }
        return tmp;
    }
    
    void addBack(int num) {
        if(num < count) {
            s.insert(num);
        }
    }
};


/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */