#include "include.h"

class Solution {
public:
    int minimumBuckets(string hamsters) {
        for (int i = 0; i < hamsters.size(); ++i) {
            if (hamsters[i] == 'H') {
                if (i > 0 && hamsters[i - 1] == 'F')
                    continue;
                if (i < hamsters.size() - 1 && hamsters[i + 1] == '.')
                    hamsters[i + 1] = 'F';
                else if (i > 0 && hamsters[i - 1] == '.')
                    hamsters[i - 1] = 'F';
                else
                    return -1;
            }
        }
        return count(begin(hamsters), end(hamsters), 'F');
    }
};
