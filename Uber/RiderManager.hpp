#pragma once
#include "Rider.hpp"
#include "mutex"

class RiderManager {
private:
    RiderManager() {}
    static RiderManager* riderManagerInstance;
    static mutex mtx;
    unordered_map<string, Rider*> riderMap;
public:
    static RiderManager* getRiderManager();
    void addRider(string id, Rider* rider);
    Rider* getRider(string id);
};