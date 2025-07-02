#include "../include.h"

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int x = 0, y = 0;
        for (const string& command : commands) {
            if (command == "UP") {
                y--;
            } else if (command == "DOWN") {
                y++;
            } else if (command == "LEFT") {
                x--;
            } else if (command == "RIGHT") {
                x++;
            }
            if(x < 0 || x >= n || y < 0 || y >= n) {
                return -1; // Out of bounds
            }
        }
        return y * n + x;
    }
};