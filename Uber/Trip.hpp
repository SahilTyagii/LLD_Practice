#pragma once;

#include "Rider.hpp"
#include "Driver.hpp"
#include "Common.hpp"
#include "PricingStrategy.hpp"
#include "MatchingStrategy.hpp"
using namespace std;

class Trip {
private:
    Rider* rider;
    Driver* driver;
    Location* srcLoc;
    Location* destLoc;
    TRIP_STATUS status;
    int tripId;
    double price;
    PricingStrategy* pricingStrategy;
    MatchingStrategy* matchingStrategy;
public:
    Trip(Rider* rider, Driver* driver, Location* srcLoc, Location* destLoc, double price, PricingStrategy* pricingStrategy, MatchingStrategy* MatchingStrategy):
    rider(rider), driver(driver), srcLoc(srcLoc), destLoc(destLoc), price(price), pricingStrategy(pricingStrategy), matchingStrategy(matchingStrategy) {
        status = TRIP_STATUS::DRIVER_ON_THE_WAY;
        tripId = nextTripId++;
    }

    int getTripId() {
        return tripId;
    }

    void displayTripDetails() {
        cout << endl;
        cout << "Trip id: " << tripId;
        cout << "Rider: " << rider->getName() << endl;
        cout << "Driver: " << driver->getName() << endl;
        cout << "Price: $" << price << endl;
        cout << "Locations: " << srcLoc->latitude << ", " << srcLoc->longitude << " to " << destLoc->latitude << ", " << destLoc->longitude << endl;
    }
};
