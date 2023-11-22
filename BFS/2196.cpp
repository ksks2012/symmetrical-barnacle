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
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        int m = des.size();

        unordered_map<int, TreeNode*> tmp;
        unordered_map<int, bool> par;
        TreeNode *root = nullptr;

        for(int i = 0; i < m; i++) {
            // Create
            if(tmp.find(des[i][0]) == tmp.end()) {
                tmp[des[i][0]] = new TreeNode(des[i][0]);
            } 
            if(tmp.find(des[i][1]) == tmp.end()) {
                tmp[des[i][1]] = new TreeNode(des[i][1]);
            } 

            // Link
            if(des[i][2] == 1) {
                tmp[des[i][0]]->left = tmp[des[i][1]];
            } else {
                tmp[des[i][0]]->right = tmp[des[i][1]];
            }

            // Save has parent or not
            if(par.find(des[i][0]) == par.end()) {
                par[des[i][0]] = false;
            }
            par[des[i][1]] = true;
        }

        for(auto &i : par) {
            if(i.second == false) {
                root = tmp[i.first];
            }
        }

        return root;
    }
};