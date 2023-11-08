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
class FindElements {
public:
    TreeNode* root;

    void recovery(TreeNode* root) {
        if(root == nullptr) return;

        if(root->left != nullptr)
            root->left->val = root->val * 2 + 1;
        if(root->right != nullptr)
            root->right->val = root->val * 2 + 2;

        recovery(root->left);
        recovery(root->right);
    }

    FindElements(TreeNode* root) {
        this->root = root;
        root->val = 0;
        recovery(root);
    }

    bool DFS(TreeNode* root, int target) {
        if(root == nullptr) 
            return false;

        if(root->val == target)
            return true;

        return DFS(root->left, target) || DFS(root->right, target);
    }
    
    bool find(int target) {
        return DFS(root, target);
    }
};

// with set in find
class FindElements {
public:
    TreeNode* root;
    unordered_set<int> val;

    void recovery(TreeNode* root) {
        if(root == nullptr) return;

        val.insert(root->val);

        if(root->left != nullptr) {
            root->left->val = root->val * 2 + 1;
        }
            
        if(root->right != nullptr) {
            root->right->val = root->val * 2 + 2;
        }

        recovery(root->left);
        recovery(root->right);
    }

    FindElements(TreeNode* root) {
        this->root = root;
        root->val = 0;
        val.insert(root->val);
        recovery(root);
    }

    bool find(int target) {
        return val.count(target);
    }
};

// bitset in find
class FindElements {
public:
    TreeNode* root;
    bitset<10000000> tmp;
    void recovery(TreeNode* root) {
        if(root == nullptr) return;
        
        this->tmp.set(root->val);

        if(root->left != nullptr) {
            root->left->val = root->val * 2 + 1;
        }
            
        if(root->right != nullptr) {
            root->right->val = root->val * 2 + 2;
        }
            

        recovery(root->left);
        recovery(root->right);
    }

    FindElements(TreeNode* root) {
        this->root = root;
        root->val = 0;
        recovery(root);
    }

    bool find(int target) {
        return this->tmp.test(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */