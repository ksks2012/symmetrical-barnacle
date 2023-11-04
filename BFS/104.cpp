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
// Time: O(n), Space: O(n)
class Solution {
public:
    void inorder(TreeNode* node, int level, int &max_level) {
        if(node == nullptr)
            return;
        max_level = max(level, max_level);

        if(node->left != nullptr) {
            inorder(node->left, level + 1, max_level);
        }
        if(node->right != nullptr) {
            inorder(node->right, level + 1, max_level);
        }
    }
    
    int maxDepth(TreeNode* root) {
        int ans = 0;
        inorder(root, 1, ans);
        return ans;
    }
};

// Time: O(n), Space: O(n)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int max_left = maxDepth(root->left);
        int max_right = maxDepth(root->right);
        return max(max_left, max_right)+1;
    }
};

// Time: O(n), Space: O(n)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode *> q;
        int ans = 0;
        if(root == nullptr)
            return ans;
        q.push(root);

        while(!q.empty()) {
            int q_size = q.size();
            for(int i = 0; i < q_size; i++) {
                TreeNode *top = q.front();
                q.pop();
                if(top->left != nullptr) {
                    q.push(top->left);
                }
                if(top->right != nullptr) {
                    q.push(top->right);
                }
            }
            ans++;
        }
        
        return ans;
    }
};