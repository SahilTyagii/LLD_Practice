#pragma once

#include "TripMetaData.hpp"
#include "LeastTimeBasedMatchingStrategy.hpp"
#include "DefaultPricingStrategy.hpp"
#include "RatingBasedPricingStrategy.hpp"
#include "Common.hpp"
#include <mutex>

using namespace std;

class StrategyManager {
private:
    StrategyManager() {};
    static StrategyManager* strategyManagerInstance;
    static mutex mtx;
public:
    static StrategyManager* getStrategyManager();
    PricingStrategy* determinePricingStrategy(TripMetaData* tripMetaData);
    MatchingStrategy* determineMatchingStrategy(TripMetaData* tripMetaData);
};
