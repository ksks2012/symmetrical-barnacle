#include "include.h"

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
    int pathSum(TreeNode* root, int targetSum) {
        int res = 0;
        unordered_map<long long, int> tmp{{0, 1}};
        auto DFS = [&](this auto&& DFS, TreeNode* node, long long s) {
            if (node == nullptr) {
                return;
            }
            s += node->val;
            res += tmp.contains(s-targetSum) ? tmp[s - targetSum] : 0;
            tmp[s]++;
            DFS(node->left, s);
            DFS(node->right, s);
            tmp[s]--; // restore
        };
        DFS(root, 0);
        return res;
    }
};
