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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        bool odd = false;

        while(!q.empty()) {
            int size = q.size();
            int prev;

            if(odd)
                prev = INT_MAX;
            else
                prev = 0;

            for(int i = 0; i < size; i++) {
                TreeNode* tmp = q.front();
                q.pop();
                if(odd) {
                    if(tmp->val % 2 == 1 || tmp->val >= prev) return false;
                    prev = tmp->val;
                } else {
                    if(tmp->val % 2 == 0 || tmp->val <= prev) return false;
                    prev = tmp->val;
                }

                if(tmp->left) 
                    q.push(tmp->left);
                if(tmp->right) 
                    q.push(tmp->right);
            }
            odd = !odd;
        }

        return true;
    }
};