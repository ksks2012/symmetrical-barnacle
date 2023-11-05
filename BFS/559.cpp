#include "../include.h"

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
// Time: O(n), Space: O(n)
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;
        int depth = 0;
        for (auto child : root->children) depth = max(depth, maxDepth(child));
        return 1 + depth;
    }
};

// Time: O(n), Space: O(n)
class Solution {
public:
    int maxDepth(Node* root) {
        queue<Node *> q;
        int ans = 0;
        if(root == nullptr)
            return ans;
        q.push(root);

        while(!q.empty()) {
            int q_size = q.size();
            for(int i = 0; i < q_size; i++) {
                Node *top = q.front();
                q.pop();
                for(int j = 0; j < top->children.size(); j++) {
                    q.push(top->children[j]);
                }
            }
            ans++;
        }
        
        return ans;
    }
};