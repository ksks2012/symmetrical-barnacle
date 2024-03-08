#include "../include.h"

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        auto inside = [&](int x, int y) {
            return (x - xCenter) * (x - xCenter) + (y - yCenter) * (y - yCenter) <= radius * radius; 
        };
        // check inside
        if (x1 <= xCenter && xCenter <= x2 && y1 <= yCenter && yCenter <= y2)
            return true;

        // check point
        for (auto x = max(x1, xCenter - radius); x <= min(x2, xCenter + radius); ++x) {
            if (inside(x, y1) || inside(x, y2))
                return true;
        }
        for (auto y = max(y1, yCenter - radius); y <= min(y2, yCenter + radius); ++y) {
            if (inside(x1, y) || inside(x2, y))
                return true;                             
        }
        return false;
    }
};