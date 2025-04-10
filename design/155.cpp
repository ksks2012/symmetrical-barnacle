#include "include.h"

class MinStack {
public:
    void push(int x) {
        valueStack.push(x);

        if (minStack.empty() || minStack.top() >= x) {
            minStack.push(x);
        }
    }

    void pop() {
        int v = valueStack.top();
        valueStack.pop();

        if (v == minStack.top()) {
            minStack.pop();
        }
    }

    int top() {
        return valueStack.top();
    }

    int getMin() {
        return minStack.top();
    }

private:
    std::stack<int> valueStack, minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */