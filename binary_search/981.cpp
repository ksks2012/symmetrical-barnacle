#include "include.h"

// votrubac
class TimeMap {
public:
    unordered_map<string, map<int, string>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].insert({ timestamp, value });
    }
    
    string get(string key, int timestamp) {
        // binary search for map
        auto it = m[key].upper_bound(timestamp);
        return it == m[key].begin() ? "" : prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

