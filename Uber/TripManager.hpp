#pragma once

#include "Trip.hpp"
#include "TripMetaData.hpp"
#include "RiderManager.hpp"
#include "DriverManager.hpp"
#include "StrategyManager.hpp"
#include <mutex>
using namespace std;

class TripManager {
private:
    static TripManager* tripManagerInstance;
    static mutex mtx;
    RiderManager* riderManager;
    DriverManager* driverManager;
    unordered_map<int, TripMetaData*> tripMetaDataMap;
    unordered_map<int, Trip*> tripMap;
    TripManager() {
        riderManager = RiderManager::getRiderManager();
        driverManager = DriverManager::getDriverManager();
    }
public:
    static TripManager* getTripManager();
    void createTrip(Rider* rider, Location* srcLoc, Location* desLoc);
    unordered_map<int, Trip*> getTripMap();
};