#include "include.h"

class Solution {
public:
    struct node {
        int val;
        int level;
    };
    // Returns minimum number of operations
    // needed to convert x into y using BFS
    int minOperations(int x, int y) {
        // To keep track of visited numbers
        // in BFS.
        set<int> visit;
    
        // Create a queue and enqueue x into it.
        queue<node> q;
        node n = { x, 0 };
        q.push(n);
    
        // Do BFS starting from x
        while (!q.empty()) {
            // Remove an item from queue
            node t = q.front();
            q.pop();
    
            // If the removed item is target
            // number y, return its level
            if (t.val == y)
                return t.level;
    
            // Mark dequeued number as visited
            visit.insert(t.val);
    
            // If we can reach y in one more step
            if(t.val % 11 == 0 && t.val / 11 == y) {
                return t.level + 1;
            }
            if(t.val % 5 == 0 && t.val / 5 == y) {
                return t.level + 1;
            }
            if(t.val + 1 == y) {
                return t.level + 1;
            }
            if(t.val - 1 == y) {
                return t.level + 1;
            }

            // Insert children of t if not visited
            // already
            if (t.val % 11 == 0 && visit.find(t.val / 11) == visit.end()) {
                n.val = t.val / 11;
                n.level = t.level + 1;
                q.push(n);
            }
            if (t.val % 5 == 0 && visit.find(t.val / 5) == visit.end()) {
                n.val = t.val / 5;
                n.level = t.level + 1;
                q.push(n);
            }
            if (t.val + 1 >= 0
                && visit.find(t.val + 1) == visit.end()) {
                n.val = t.val + 1;
                n.level = t.level + 1;
                q.push(n);
            }
            if (t.val - 1 >= 0
                && visit.find(t.val - 1) == visit.end()) {
                n.val = t.val - 1;
                n.level = t.level + 1;
                q.push(n);
            }
        }
        return 0;
    }

    int minimumOperationsToMakeEqual(int x, int y) {
        return minOperations(x, y);   
    }
};