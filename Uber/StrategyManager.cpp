#pragma once

#include "StrategyManager.hpp"
using namespace std;

StrategyManager* StrategyManager::strategyManagerInstance = nullptr;
mutex StrategyManager::mtx;

StrategyManager* StrategyManager::getStrategyManager() {
    if (strategyManagerInstance == nullptr) {
        mtx.lock();
        if (strategyManagerInstance == nullptr) {
            strategyManagerInstance = new StrategyManager();
        }
        mtx.unlock();
    }
    return strategyManagerInstance;
}

PricingStrategy* StrategyManager::determinePricingStrategy(TripMetaData* tripMetaData) {
    cout << "Based on location and other factors setting the best pricing strategy\n";
    return new DefaultPricingStrategy();
}

MatchingStrategy* StrategyManager::determineMatchingStrategy(TripMetaData* tripMetaData) {
    cout << "Based on location and other factors setting the best driver matching strategy\n";
    return new LeastTimeBasedMatchingStrategy();
}