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
// Time: O(n), Space: O(n)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) {
            return root;
        }
        TreeNode* left_tmp = root->left;
        TreeNode* right_tmp = root->right;
        root->left = invertTree(right_tmp);
        root->right = invertTree(left_tmp);
        return root;
    }
};

// Time: O(n), Space: O(n)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode *> q;
        if(root == nullptr)
            return root;
        q.push(root);

        while(!q.empty()) {
            TreeNode *top = q.front();
            q.pop();
            TreeNode* left_tmp = top->left;
            TreeNode* right_tmp = top->right;
            top->left = right_tmp;
            top->right = left_tmp;
            if(top->left != nullptr) {
                q.push(top->left);
            }
            if(top->right != nullptr) {
                q.push(top->right);
            }
        }
        
        return root;
    }
};