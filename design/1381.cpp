#include "include.h"

class CustomStack {
public:
    
    vector<int> stack;
    int maxSize;
    
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        
        if(stack.size() < maxSize)
            stack.push_back(x);
        cout << maxSize << endl;
    }
    
    int pop() {
        
        if(stack.size() == 0)
            return -1;
        
        int top = stack[stack.size() - 1];
        stack.erase(stack.end() - 1);
        return top;
    }
    
    void increment(int k, int val) {
        
        for(int i = 0; i < min(k, (int)stack.size()); i ++)
            stack[i] += val;
    }    
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */