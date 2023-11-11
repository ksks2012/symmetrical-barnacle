#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <unordered_map>
#include <iostream>
#include <set>
#include <unordered_set>
#include <stack>
#include <numeric>
#include <bitset> 
#include <queue>

using namespace std;

vector<int> way = {1, 0, -1, 0, 1};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};