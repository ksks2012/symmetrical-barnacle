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
class Solution {
private:
    TreeNode* construct(TreeNode* root,int val,int depth) {
        int level = 1;
        TreeNode* dummy = root;
        queue<TreeNode*> q;
        q.push(root);
        while(level != depth - 1) {
            level++;
            int val = q.size();
            for(int i = 0; i < val; i++) {
                auto it = q.front();
                q.pop();
                if(it->left) 
                    q.push(it->left);
                if(it->right) 
                    q.push(it->right); 
            }
        }

        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            TreeNode* node1 = new TreeNode(val);
            if(it->left) 
                node1->left = it->left;
            it->left = node1;
            TreeNode* node2 = new TreeNode(val);
            if(it->right) 
                node2->right = it->right;
            it->right = node2;
        }
        return dummy;
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode *node = new TreeNode(val);
            node->left = root;
            return node;
        }
        return construct(root, val, depth);
        
    }
};