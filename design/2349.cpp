#include "include.h"

class NumberContainers {
public:
    unordered_map<int, int> idx_val;
    unordered_map<int, set<int>> num_idx;

    NumberContainers() {
        
    }
    
    /**
     * If the index already exists and its value is different from the given number,
     * the index is removed from the previous value's set. Then, the index is updated
     * with the new number, and the index is added to the set of the new number.
     * 
     * @param index The index to be changed.
     * @param number The new value to be assigned to the index.
     */
    void change(int index, int number) {
        if(idx_val.find(index) != idx_val.end() && idx_val[index] != number) {
            num_idx[idx_val[index]].erase(index);
        }
        idx_val[index] = number;
        num_idx[number].insert(index);
    }
    
    int find(int number) {
        if(num_idx.find(number) != num_idx.end() && num_idx[number].size() > 0) {
            return *num_idx[number].begin(); 
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */