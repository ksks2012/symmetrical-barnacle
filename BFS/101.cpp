#include "../include.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isMirror(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr && root2 == nullptr) 
            return true;
        if(root1 == nullptr || root2 == nullptr) 
            return false;
        return root1->val == root2->val && isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
    }

    bool isSymmetric(TreeNode* root) {
       return isMirror(root, root); 
    }
};

#define TREE_PAIR pair<TreeNode*, TreeNode*>
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        stack<TREE_PAIR> s;
        if(root == nullptr) {
            return false;
        }
        s.push(TREE_PAIR(root->left, root->right));

        while(!s.empty()) {
            TREE_PAIR top = s.top();
            s.pop();
            TreeNode* left = top.first;
            TreeNode* right = top.second;

            if(left == nullptr && right == nullptr) {
                continue;
            }
            if(left == nullptr || right == nullptr) {
                return false;
            }

            if(left->val == right->val) {
                s.push(TREE_PAIR(left->left, right->right));
                s.push(TREE_PAIR(left->right, right->left));
            } else {
                return false;
            }
        }
        return true;
    }
};