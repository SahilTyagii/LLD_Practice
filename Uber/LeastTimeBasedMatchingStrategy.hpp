#pragma once

#include "MatchingStrategy.hpp"
using namespace std;

class LeastTimeBasedMatchingStrategy: public MatchingStrategy {
public:
    Driver* matchDriver(TripMetaData* tripMetaData) const override {
        DriverManager* driverManager = DriverManager::getDriverManager();

        if (driverManager->getDriverMap().empty()) {
            cout << "No drivers available!\n";
        }

        cout << "Using quadtree to see nearest cabs, using driver manager to get details of drivers and send notifications" << endl;
        Driver* driver = driverManager->getDriverMap().begin()->second;
        cout << "Setting " << driver->getName() << " as Driver!\n";
        tripMetaData->setDriverRating(driver->getRating());
        return driver;
    }
};