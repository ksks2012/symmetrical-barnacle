#include "include.h"

class BrowserHistory {
    vector<string> history;
    int cur = 0; // current page: history[cur]

public:
    BrowserHistory(string homepage) : history{homepage} {}

    void visit(string url) {
        cur++;
        history.resize(cur);
        history.push_back(url);
    }

    string back(int steps) {
        cur = max(cur - steps, 0);
        return history[cur];
    }

    string forward(int steps) {
        cur = min(cur + steps, (int) history.size() - 1);
        return history[cur];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */