#include "include.h"

class MyStack {
public:
    queue<int> que;
    // Push element x onto stack.
    void push(int x) {
        que.push(x);
        for (int i = 0; i < que.size() - 1; ++i) {
            que.push(que.front());
            que.pop();
        }
    }

    // Removes the element on top of the stack.
    int pop() {
        int tmp = que.front();
        que.pop();
        return tmp;
    }

    // Get the top element.
    int top() {
        return que.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return que.empty();
    }
};