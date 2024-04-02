#include "include.h"

class Solution {
public:
    long long numberOfWeeks(vector<int>& m) {
	    if(m.size() == 1) {
            return 1;
        }
        sort(m.begin(), m.end());
        long long sum = accumulate(m.begin(), m.end() - 1, 0LL);
        long long last = m.back();
        if(sum >= last) {
            return sum + last;
        }
        return sum * 2 + 1;
    }
};

// votrubac
class Solution {
public:
    long long numberOfWeeks(vector<int>& m) {
        long long sum = accumulate(m.begin(), m.end(), 0LL);
        long long maxi = *max_element(m.begin(), m.end());
        return min(sum, 2 * (sum - maxi) + 1);
    }
};
