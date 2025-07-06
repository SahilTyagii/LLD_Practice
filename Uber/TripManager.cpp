#include "TripManager.hpp"
using namespace std;

TripManager* TripManager::tripManagerInstance = nullptr;
mutex TripManager::mtx;

TripManager* TripManager::getTripManager() {
    if (tripManagerInstance == nullptr) {
        mtx.lock();
        if (tripManagerInstance == nullptr) {
            tripManagerInstance = new TripManager();
        }
        mtx.unlock();
    }
    return tripManagerInstance;
}

void TripManager::createTrip(Rider* rider, Location* srcLoc, Location* destLoc) {
    TripMetaData* tripMetaData = new TripMetaData(rider->getRating(), srcLoc, destLoc);
    StrategyManager* strategyManager = StrategyManager::getStrategyManager();
    PricingStrategy* pricingStrategy = strategyManager->determinePricingStrategy(tripMetaData);
    MatchingStrategy* matchingStrategy = strategyManager->determineMatchingStrategy(tripMetaData);

    Driver* driver = matchingStrategy->matchDriver(tripMetaData);
    double tripPrice = pricingStrategy->calculatePrice(tripMetaData);

    Trip* trip = new Trip(rider, driver, srcLoc, destLoc, tripPrice, pricingStrategy, matchingStrategy);
    int tripId = trip->getTripId();
    tripMap[tripId] = trip;
    tripMetaDataMap[tripId] = tripMetaData;
}

unordered_map<int, Trip*> TripManager::getTripMap() {
    return tripMap;
}