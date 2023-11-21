#include "../include.h"

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
		if(node == NULL)
			return NULL;
		unordered_map <int, Node*> m;
		stack<Node*> s;
		s.push(node);

		while(!s.empty()) {
			Node* cur = s.top();
			s.pop();
			if(m.find(cur->val) == m.end()) {
				m[cur->val] = new Node(cur->val);
			}
			for(int i = 0; i < cur->neighbors.size(); i++) {
				if(m.find(cur->neighbors[i]->val) == m.end()) {
					m[cur->neighbors[i]->val] = new Node(cur->neighbors[i]->val);
					s.push(cur->neighbors[i]);
				}
				m[cur->val]->neighbors.push_back(m[cur->neighbors[i]->val]);
			}
		}
		return m[node->val];
    }
};