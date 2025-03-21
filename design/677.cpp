#include "../include.h"

class MapSum {
public:
    unordered_map<string,int> mp;
    MapSum() {
        mp["0"] = {};
    }
    
    void insert(string key, int val) {
        mp[key] = val;
    }
    
    int sum(string prefix) {
        int res = 0;
        for(auto i : mp){
            if(prefix.compare(i.first.substr(0,prefix.size())) == 0)
                res += i.second;
        }
        return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */