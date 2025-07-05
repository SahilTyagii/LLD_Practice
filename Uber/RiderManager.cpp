#include "RiderManager.hpp"
using namespace std;

RiderManager* RiderManager::riderManagerInstance = nullptr;
mutex RiderManager::mtx;

RiderManager* RiderManager::getRiderManager() {
    if (riderManagerInstance == nullptr) {
        mtx.lock();
        if (riderManagerInstance == nullptr) {
            riderManagerInstance = new RiderManager();
        }
        mtx.unlock();
    }
    return riderManagerInstance;
}

void RiderManager::addRider(string id, Rider* rider) {
    riderMap[id] = rider;
}

Rider* RiderManager::getRider(string id) {
    return riderMap[id];
}