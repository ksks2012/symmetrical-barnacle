#include "include.h"

// lzl124631x
// Time Complexity: O(1)
// Space Complexity: O(N)
class FrontMiddleBackQueue {
    deque<int> left, right;
    void left2right() {
        if (left.size() <= right.size()) 
            return;
        right.push_front(left.back());
        left.pop_back();
    }
    void right2left() {
        if (right.size() <= left.size() + 1) 
            return;
        left.push_back(right.front());
        right.pop_front();
    }
public:
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        left.push_front(val);
        left2right();
    }
    
    void pushMiddle(int val) {
        left.push_back(val);
        left2right();
    }
    
    void pushBack(int val) {
        right.push_back(val);
        right2left();
    }
    
    int popFront() {
        if (left.empty() && right.empty()) 
            return -1;
        int ans;
        if (left.empty()) {
            ans = right.front();
            right.pop_front();
        } else {
            ans = left.front();
            left.pop_front();
            right2left();
        }
        return ans;  
    }
    
    int popMiddle() {
        if (left.empty() && right.empty()) 
            return -1;
        int ans;
        if (left.size() == right.size()) {
            ans = left.back();
            left.pop_back();
        } else {
            ans = right.front();
            right.pop_front();
        }
        return ans; 
    }
    
    int popBack() {
        if (left.empty() && right.empty()) 
            return -1;
        int ans = right.back();
        right.pop_back();
        left2right();
        return ans;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */