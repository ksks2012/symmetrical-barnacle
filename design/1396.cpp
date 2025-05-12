#include "include.h"

class UndergroundSystem {
public:
    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t) {
        check_record[id] = { stationName, t };
    }

    void checkOut(int id, string stationName, int t) {
        string name = getStationName(check_record[id].first, stationName);
        t -= check_record[id].second;
        cnt[name].first += (double)t;
        cnt[name].second += 1;
    }

    double getAverageTime(string startStation, string endStation) {
        string name = getStationName(startStation, endStation);
        double res = cnt[name].first / (double)cnt[name].second;
        return res;
    }

private:
    string getStationName(string startStation, string endStation) {
        return startStation + "," + endStation;
    }

    unordered_map<int, pair<string, int>> check_record;
    unordered_map<string, pair<double, int>> cnt;
};


/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */