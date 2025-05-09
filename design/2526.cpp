#include "include.h"

class DataStream {
public:
    int val = 0, maxi = 0;
    int count = 0;
    DataStream(int value, int k) {
        val = value;
        maxi = k;
    }
    
    bool consec(int num) {
        if(num == val)
            count++;
        else
            count = 0;
        return count >= maxi;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */