#pragma once

#include "Driver.hpp"
#include "mutex"

using namespace std;

class DriverManager {
private:
    DriverManager() {};
    static DriverManager* driverManagerInstance;
    static mutex mtx;
    unordered_map<string, Driver*> driverMap;
public:
    static DriverManager* getDriverManager();
    void addDriver(string id, Driver* driver);
    Driver* getDriver(string id);
    unordered_map<string, Driver*> getDriverMap();
};