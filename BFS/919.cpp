#include "../include.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter {
    queue<TreeNode*> q;
    TreeNode* ans;
public:
    CBTInserter(TreeNode* root) {
        ans = root;
        q.push(root);
        while (q.front()->left && q.front()->right) {
            TreeNode* node = q.front();
            q.pop();
            q.push(node->left);
            q.push(node->right);
        }
        
    }
    
    int insert(int val) {
        int parent = q.front()->val;
        if (!q.front()->left) 
            q.front()->left = new TreeNode(val);
        else {
            TreeNode* node = q.front();
            node->right = new TreeNode(val);
            q.pop();
            q.push(node->left);
            q.push(node->right);
        }
        return parent;
    }
    
    TreeNode* get_root() {
        return ans;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */