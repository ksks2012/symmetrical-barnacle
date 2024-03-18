#include "include.h"

class LUPrefix {
public:
    set<int> s;
    int cur = 0;
    LUPrefix(int n) {
        ;
    }
    
    void upload(int video) {
        s.emplace(video);
    }
    
    int longest() {
        while(s.count(cur + 1)) {
            cur++;
        }
        return cur;
    }
};

static const int FastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}();

// Optimize
class LUPrefix {
public:
    vector<int> tmp;
    int cur = 0;

    LUPrefix(int n) {
        tmp.resize(n + 2);
    }
    
    void upload(int video) {
        tmp[video] = 1;
        while (tmp[cur + 1] == 1) {
            cur++;
        }
    }
    
    int longest() {
        return cur;
    }
};
/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */