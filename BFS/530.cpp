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
// Time: O(n^2), Space: O(n)
class Solution {
public:  
    void order(TreeNode* root, vector<int> &vec) {
        if(root == nullptr)
            return;
        vec.push_back(root->val);
        order(root->left, vec);
        order(root->right, vec);
    }
    
    int getMinimumDifference(TreeNode* root) {
        
        vector<int> vec;
        order(root, vec);
        
        int diff = INT_MAX;
        int m = vec.size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                if(i == j) {
                    continue;
                } else {
                    diff = min(diff, abs(vec[i] - vec[j]));
                }
            }
        }
        
        return diff;         
    }
};

// Time: O(n), Space: O(n)
class Solution {
public:  
    int min_dif = INT_MAX, val = -1;    
    int getMinimumDifference(TreeNode* root) {
        if (root->left != nullptr) 
            getMinimumDifference(root->left);
        if (val >= 0) 
            min_dif = min(min_dif, root->val - val);
        val = root->val;
        if (root->right != nullptr) 
            getMinimumDifference(root->right);
        return min_dif;
    }
};