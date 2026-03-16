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
    int kthSmallest(TreeNode* root, int k) {
        queue<TreeNode *> q;
        int res = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        q.push(root);

        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();

            pq.push(node->val);

            // Process the current node
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }

        while (k-- > 0 && !pq.empty()) {
            res = pq.top();
            pq.pop();
        }

        return res;
    }
};