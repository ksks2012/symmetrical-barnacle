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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr)
            return root2;
        if(root2 == nullptr)
            return root1;
        
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        
        return root1;
    }
};

// Time: O(n), Space: O(n)
#define TREE_PAIR pair<TreeNode*, TreeNode*>
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        stack<TREE_PAIR> stk;
        if(root1 == nullptr)
            return root2;
        if(root2 == nullptr)
            return root1;
        stk.push(TREE_PAIR(root1, root2));

        while(!stk.empty()) {
            TREE_PAIR top = stk.top();
            stk.pop();
            if(top.first == nullptr || top.second == nullptr) {
                continue;
            }
            top.first->val += top.second->val;
            if(top.first->left == nullptr) {
                top.first->left = top.second->left;
            } else {
                stk.push(TREE_PAIR(top.first->left, top.second->left));
            }
            if(top.first->right == nullptr) {
                top.first->right = top.second->right;
            } else {
                stk.push(TREE_PAIR(top.first->right, top.second->right));
            }
        }
        
        return root1;
    }
};