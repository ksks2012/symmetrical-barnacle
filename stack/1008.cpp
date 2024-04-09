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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size() == 0) 
            return nullptr;
        TreeNode* root = new TreeNode (preorder[0]);
        stack<TreeNode*> st;
        st.push(root);
        for (int i = 1; i < preorder.size(); ++i) {
            TreeNode* cur = new TreeNode(preorder[i]);
            TreeNode* tmp = nullptr;
            while (!st.empty() && preorder[i] > (st.top()->val)) {
                tmp = st.top();
                st.pop();
            }
            if (tmp) 
                tmp->right = cur;
            else 
                (st.top()->left) = cur;
            st.push(cur);
        }

        return root;
    }
};


class Solution {
public:
    int i = 0;
    TreeNode* bstFromPreorder(vector<int>& preorder, int bound = INT_MAX) {
        if (i == preorder.size() || preorder[i] > bound) return NULL;
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = bstFromPreorder(preorder, root->val);
        root->right = bstFromPreorder(preorder, bound);
        return root;
    }
};