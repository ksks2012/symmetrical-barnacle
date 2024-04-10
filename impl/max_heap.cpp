#include "include.h"

void max_heapify_botton_up(vector<int> &vec) {
    // the index of new node, the latest one element in slice
    int new_ele_idx = vec.size() - 1;

    while(true) {
        // get the parent node index
        int parent_idx = (new_ele_idx + 1) / 2 - 1;
        // break if the node is to the top of heap
        if(parent_idx < 0)
            break;

        // if parent node < the new node, swap
        if(vec[parent_idx] < vec[new_ele_idx]) {
            swap(vec[parent_idx], vec[new_ele_idx]);
            new_ele_idx = parent_idx;
        } else {
            break;
        }
    }

    return;
}

void max_heapify_top_down(vector<int> &vec, int last_idx) {
    int cur_idx = 0;

    while(true) {
        int child = 2 * cur_idx + 1;
        if(child > last_idx) {
            break;
        }

        if(child + 1 <= last_idx && vec[child] < vec[child + 1]) {
            child++;
        }

        if(vec[cur_idx] < vec[child]) {
            swap(vec[cur_idx], vec[child]);
            cur_idx = child;
        } else {
            break;
        }
    }

    return;
}

vector<int> build_max_heap(vector<int>& vec) {
    vector<int> max_heap;

    for(auto v : vec) {
        max_heap.push_back(v);
        max_heapify_botton_up(max_heap);
    }

    return max_heap;
}

void heap_sort(vector<int>& vec) {
    int cur_idx = vec.size() - 1;
    
    while(true) {
        if(cur_idx <= 0)
            break;

        // take the final element to the root and do heapify
        swap(vec[0], vec[cur_idx]);
        cur_idx--;
        max_heapify_top_down(vec, cur_idx);
    }
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    vector<int> heap = build_max_heap(vec);
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