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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left != nullptr && right != nullptr) {
            return root;
        }
        return left != nullptr ? left : right;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        
        // Step 1: build parent mapping (each node -> its parent)
        unordered_map<TreeNode*, TreeNode*> parent;
        parent[root] = nullptr;  // root has no parent
        
        // Use a queue to do BFS over the tree and build the parent map
        queue<TreeNode*> que;
        que.push(root);
        
        while (!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            
            if (node->left) {
                parent[node->left] = node;
                que.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                que.push(node->right);
            }
            
            // Early exit: if parents for both p and q are found, we can stop
            if (parent.count(p) && parent.count(q)) {
                break;
            }
        }
        
        // Step 2: put all nodes on the path from p to root into a set
        unordered_set<TreeNode*> ancestors;
        TreeNode* cur = p;
        while (cur) {
            ancestors.insert(cur);
            cur = parent[cur];
        }
        
        // Step 3: move up from q and return the first node that appears in ancestors
        cur = q;
        while (cur) {
            if (ancestors.count(cur)) {
                return cur;
            }
            cur = parent[cur];
        }
        
        // Shouldn't reach here (the problem guarantees p and q are in the tree)
        return nullptr;
    }
};