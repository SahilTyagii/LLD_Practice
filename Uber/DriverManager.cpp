#include "DriverManager.hpp"
using namespace std;

DriverManager* DriverManager::driverManagerInstance = nullptr;
mutex DriverManager::mtx;

DriverManager* DriverManager::getDriverManager() {
    if (driverManagerInstance == nullptr) {
        mtx.lock();
        if (driverManagerInstance == nullptr) {
            driverManagerInstance = new DriverManager();
        }
        mtx.unlock();
    }
    return driverManagerInstance;
}

void DriverManager::addDriver(string id, Driver* driver) {
    driverMap[id] = driver;
}

Driver* DriverManager::getDriver(string id) {
    return driverMap[id];
}

unordered_map<string, Driver*> DriverManager::getDriverMap() {
    return driverMap;
}