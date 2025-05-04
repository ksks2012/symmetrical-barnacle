#include "include.h"

class OrderedStream {
    vector<string> tmp;
    int ptr = 1;

public:
    OrderedStream(int n) : tmp(n + 1) {}

    vector<string> insert(int idKey, string value) {
        tmp[idKey] = move(value);
        int start = ptr;
        while (ptr < tmp.size() && !tmp[ptr].empty()) {
            ptr++;
        }
        return {tmp.begin() + start, tmp.begin() + ptr};
    }
};
/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */