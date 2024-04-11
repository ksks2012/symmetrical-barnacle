#include "include.h"

void min_heapify_botton_up(vector<int> &vec) {
    // the index of new node, the latest one element in slice
    int new_ele_idx = vec.size() - 1;
    // get the parent node index
    int parent_idx = (new_ele_idx + 1) / 2 - 1;

    // break if the node is to the top of heap
    while(parent_idx >= 0) {
        // if parent node > the new node, swap
        if(vec[parent_idx] > vec[new_ele_idx]) {
            swap(vec[parent_idx], vec[new_ele_idx]);
            new_ele_idx = parent_idx;
        } else {
            break;
        }
        parent_idx = (new_ele_idx + 1) / 2 - 1;
    }

    return;
}

void min_heapify_top_down(vector<int> &vec, int last_idx) {
    int cur_idx = 0;
    int child = 2 * cur_idx + 1;

    while(child <= last_idx) {
        if(child + 1 <= last_idx && vec[child] > vec[child + 1]) {
            child++;
        }

        if(vec[cur_idx] > vec[child]) {
            swap(vec[cur_idx], vec[child]);
            cur_idx = child;
        } else {
            break;
        }
        child = 2 * cur_idx + 1;
    }

    return;
}

vector<int> build_min_heap(vector<int>& vec) {
    vector<int> min_heap;

    for(auto v : vec) {
        min_heap.push_back(v);
        min_heapify_botton_up(min_heap);
    }

    return min_heap;
}

void heap_sort(vector<int>& vec) {
    int cur_idx = vec.size() - 1;
    
    while(cur_idx > 0) {
        // take the final element to the root and do heapify
        swap(vec[0], vec[cur_idx]);
        cur_idx--;
        min_heapify_top_down(vec, cur_idx);
    }
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    vector<int> heap = build_min_heap(vec);
    for(auto i : heap) {
        cout << i << " ";
    }
    cout << endl;

    heap_sort(heap);
    for(auto i : heap) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}