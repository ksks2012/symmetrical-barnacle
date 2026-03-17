#include "../include.h"

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode *buildTree(vector<int> &preorder, int pLeft, int pRight, vector<int> &inorder, int iLeft, int iRight) {
        if (pLeft > pRight || iLeft > iRight) return NULL;
        int i = 0;
        for (i = iLeft; i <= iRight; ++i) {
            if (preorder[pLeft] == inorder[i]) break;
        }
        TreeNode *cur = new TreeNode(preorder[pLeft]);
        cur->left = buildTree(preorder, pLeft + 1, pLeft + i - iLeft, inorder, iLeft, i - 1);
        cur->right = buildTree(preorder, pLeft + i - iLeft + 1, pRight, inorder, i + 1, iRight);
        return cur;
    }
};

class Solution {
public:
    // Used for fast lookup of value -> inorder index mapping
    unordered_map<int, int> inorderIndex;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Build hash map in advance: value -> index in inorder array
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndex[inorder[i]] = i;
        }
        
        return build(preorder, 0, preorder.size() - 1,
                     inorder,   0, inorder.size() - 1);
    }
    
private:
    TreeNode* build(vector<int>& preorder, int preL, int preR,
                    vector<int>& inorder,  int inL,  int inR) {
        // Invalid range, return null
        if (preL > preR || inL > inR) {
            return nullptr;
        }
        
        // First element of preorder is root of current subtree
        int rootVal = preorder[preL];
        
        // Find root's index in inorder using hash map in O(1)
        int rootInIndex = inorderIndex[rootVal];
        
        // Compute size of left subtree (number of nodes)
        int leftSize = rootInIndex - inL;
        
        // Create current node
        TreeNode* root = new TreeNode(rootVal);
        
        // Recursively build left subtree
        root->left = build(preorder, preL + 1,           preL + leftSize,
                           inorder,   inL,               rootInIndex - 1);
        
        // Recursively build right subtree
        root->right = build(preorder, preL + leftSize + 1, preR,
                            inorder,   rootInIndex + 1,    inR);
        
        return root;
    }
};