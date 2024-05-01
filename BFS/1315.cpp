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
public:
    int sum = 0;
    void DFS(TreeNode* current, TreeNode* parent, TreeNode* grandParent) {
        // base case 
        if (current == nullptr) 
            return;
        if (grandParent != nullptr && grandParent->val % 2 == 0) {
            sum += current->val;
        }
        // ( newChild, parent, GrandParent)
        DFS(current->left, current, parent);
        DFS(current->right, current, parent);
    }

    int sumEvenGrandparent(TreeNode* root) {
        DFS(root, nullptr, nullptr);
        return sum;
    }
};