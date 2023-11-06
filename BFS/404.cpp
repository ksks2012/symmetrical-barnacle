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
// Recursive DFS: Time: O(n), Space: O(n)
class Solution {
public:
    int sumOfLeftLeaves(TreeNode *root) {
        if(root == nullptr)
            return 0;
        int sum = 0;
        sum += sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        // check final leaves
        if(root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
            sum += root->left->val;
        }
        return sum;
    }
};

// Recursive DFS: minimize
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root, bool isleft = false) {
        if (!root) 
            return 0;
        if (!root->left && !root->right) 
            return isleft ? root->val : 0;
        return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
    }
};

// Iterative DFS
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        stack<pair<TreeNode*, bool>> s;
        s.push({root, false});
        int ans = 0;
        while(s.size()) {
            auto [cur, isLeft] = s.top(); s.pop();
            if(!cur -> left && !cur -> right && isLeft) 
                ans += cur -> val;
            if(cur -> right) s.push({cur -> right, false});
            if(cur -> left) s.push({cur -> left, true});
        }
        return ans;
    }
};

// Iterative BFS
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        queue<pair<TreeNode*, bool>> q;
        q.push({root, false});
        int ans = 0;
        while(q.size()) {
            auto [cur, isLeft] = q.front(); q.pop();
            if(!cur -> left && !cur -> right && isLeft) 
                ans += cur -> val;
            if(cur -> right) q.push({cur -> right, false});
            if(cur -> left) q.push({cur -> left, true});
        }
        return ans;
    }
};

// Morris Traversal: Time: O(n), Space: O(1)
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        while(root) {
            if(root -> left) {
                auto pre = root -> left;  // find predecessor of root
                while(pre -> right && pre -> right != root) 
                    pre = pre -> right;
                // make root as right child of predecessor (temporary link)
                if(!pre -> right) {
                    pre -> right = root;
                    root = root -> left;                    
                }
                else {
                    pre -> right = nullptr;  // revert the changes - remove temporary link
                    // add to sum if node is left child and a leaf
                    if(pre == root -> left && !pre -> left) ans += pre -> val;
                    root = root -> right;
                }
            } 
			else root = root -> right;
        }
        return ans;
    }
};