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
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        queue<Node *> q;
        q.push(root);
    
        while(!q.empty()) {
            vector<int> tmp;
            int q_size = q.size();
            for(int i = 0; i < q_size; i++) {
                Node *node = q.front();
                q.pop();
                if(node != NULL) {
                    for(int j = 0; j < node->children.size(); j++) {
                        q.push(node->children[j]);
                    }
                    tmp.push_back(node->val);
                }  
            }
            ans.push_back(tmp);
        }

        return ans;
    }
};