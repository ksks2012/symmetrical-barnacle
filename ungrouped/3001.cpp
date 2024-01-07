#include "include.h"

class Solution {
public:
    int minMovesToCaptureTheQueen(int x1, int y1, int x2, int y2, int x3, int y3) {
        if(abs(x2 - x3) == abs(y2 - y3)) {
            // check block
            int wx = 1;
            int wy = 1;
            if(x2 - x3 > 0)
                wx = -1;
            if(y2 - y3 > 0)
                wy = -1;

            int tx = x2;
            int ty = y2;
            while(tx != x3 && ty != y3) {
                tx += wx;
                ty += wy;
                // R between B & Q
                if(tx == x1 && ty == y1) {
                    return 2;
                }
            }
            // B & Q in cross line
            if(tx == x3 && ty == y3) {
                return 1;
            }
        }

        if(x1 == x3) {
            if(x1 == x2) {
                // check block
                int wx = 0;
                int wy = 1;
                if(y1 - y3 > 0)
                    wy = -1;
                
                int tx = x1;
                int ty = y1;
                while(ty != y3) {
                    ty += wy;
                    if(ty == y2) {
                        return 2;
                    }  
                }
                // R & Q in same line without R
                return 1;
            } else {
                // R & Q in same line
                return 1;
            }     
        } else if (y1 == y3) {
            if(y1 == y2) {
                // check block
                int wx = 1;
                int wy = 0;
                if(x1 - x3 > 0)
                    wx = -1;
                
                int tx = x1;
                int ty = y1;
                while(tx != x3) {
                    tx += wx;
                    if(tx == x2) {
                        return 2;
                    }
                }
                // R & Q in same line without R
                return 1;
            } else {
                // R & Q in same line
                return 1;
            }
        }

        return 2;
    }
};
