#include "include.h"

// DP
class Solution {
public:
    int numSquares(int n) {
		vector<int> dp(n + 1, INT_MAX);
		dp[0] = 0;

		for(int i = 1; i <= n; i++) {
			for(int j = 1; j * j <= i; j++) {
				dp[i] = min(dp[i], dp[i - j * j] + 1);
			}
		}
		return dp[n];
    }
};

// BFS Solution
class Solution {
public:
    int numSquares(int n) {
        if (n <= 0) {
            return 0;
        }
        
        // perfectSquares contain all perfect square numbers which 
        // are smaller than or equal to n.
        vector<int> perfect_squares;
        // count[i - 1] = the least number of perfect 
        // square numbers which sum to i.
        vector<int> count(n);
        
        // Get all the perfect square numbers which are smaller than 
        // or equal to n.
        for (int i = 1; i * i <= n; i++) {
            perfect_squares.push_back(i * i);
            count[i * i - 1] = 1;
        }
        
        // If n is a perfect square number, return 1 immediately.
        if (perfect_squares.back() == n) {
            return 1;
        }
        
        // Consider a graph which consists of number 0, 1,...,n as
        // its nodes. Node j is connected to node i via an edge if  
        // and only if either j = i + (a perfect square number) or 
        // i = j + (a perfect square number). Starting from node 0, 
        // do the breadth-first search. If we reach node n at step 
        // m, then the least number of perfect square numbers which 
        // sum to n is m. Here since we have already obtained the 
        // perfect square numbers, we have actually finished the 
        // search at step 1.
        queue<int> q;
        for (auto& i : perfect_squares) {
            q.push(i);
        }
        
        int tmp = 1;
        while (!q.empty()) {
            tmp++;
            
            int searchQSize = q.size();
            for (int i = 0; i < searchQSize; i++) {
                int tmp = q.front();
                // Check the neighbors of node tmp which are the sum 
                // of tmp and a perfect square number.
                for (auto& j : perfect_squares) {
                    if (tmp + j == n) {
                        // We have reached node n.
                        return tmp;
                    } else if ((tmp + j < n) && (count[tmp + j - 1] == 0)) {
                        // If count[tmp + j - 1] > 0, this is not 
                        // the first time that we visit this node and we should 
                        // skip the node (tmp + j).
                        count[tmp + j - 1] = tmp;
                        q.push(tmp + j);
                    } else if (tmp + j > n) {
                        // We don't need to consider the nodes which are greater ]
                        // than n.
                        break;
                    }
                }
                
                q.pop();
            }
        }
        
        return 0;
    }
};