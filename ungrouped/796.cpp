#include "../include.h"

// Brute force
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) 
            return false;
        int n = s.size();

        for (int rotationCount = 0; rotationCount < n; ++rotationCount) {
            rotate(s.begin(), s.begin() + 1, s.end());
            if (s == goal) 
                return true;
        }
        return false;
    }
};

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) 
            return false;

        string tmp = s + s;

        return tmp.find(goal) < tmp.length();
    }
};