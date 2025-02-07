#include "include.h"

class SnapshotArray {
    vector<vector<pair<int, int>>> updates;
    int cur_snap;

public:
    SnapshotArray(int length) {
        updates.resize(length);
        cur_snap = 0;
    }

    void set(int index, int val) {
        updates[index].emplace_back(cur_snap, val);
    }

    int snap() {
        return cur_snap++;
    }

    int get(int index, int snap_id) {
        int idx = upper_bound(updates[index].begin(), updates[index].end(), make_pair(snap_id, INT_MAX)) - updates[index].begin();
        if (idx == 0) 
            return 0;
        return updates[index][idx - 1].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */