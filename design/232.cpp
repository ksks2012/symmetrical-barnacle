#include "include.h"

class MyQueue {
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        q.push(x);   
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int value = q.front();
        q.pop();
        return value;
    }
    
    /** Get the front element. */
    int peek() {
        return q.front();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */


 class MyQueue {
private:
    stack<int> in_stack, out_stack;

    void transfer() {
        while (!in_stack.empty()) {
            out_stack.push(in_stack.top());
            in_stack.pop();
        }
    }
    
public:
    MyQueue() {}

    void push(int x) {
        in_stack.push(x);
    }

    int pop() {
        if (out_stack.empty()) {
            transfer();
        }
        int topElement = out_stack.top();
        out_stack.pop();
        return topElement;
    }

    int peek() {
        if (out_stack.empty()) {
            transfer();
        }
        return out_stack.top();
    }

    bool empty() {
        return in_stack.empty() && out_stack.empty();
    }
};