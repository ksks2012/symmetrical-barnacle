#include "../include.h"

class RLEIterator {
public:
    RLEIterator(const std::vector<int>& encoding) {
        m.reserve(encoding.size() / 2);
        for (int i = 0; i < encoding.size(); i += 2) {
            m.emplace_back(encoding[i], encoding[i + 1]);
        }
    }
    int next(int n) {
        while (cur_idx < m.size() && m[cur_idx].first < n) {
            n -= m[cur_idx].first;
            m[cur_idx].first = 0;
            ++cur_idx;
        }
        if (cur_idx >= m.size())
            return -1;
        m[cur_idx].first -= n;
        return m[cur_idx].second;
    }
private:
    int cur_idx = 0;
    std::vector<std::pair<int, int>> m;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */