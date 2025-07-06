#pragma once

#include "TripMetaData.hpp"

using namespace std;

class PricingStrategy {
public:
    virtual double calculatePrice(TripMetaData* tripMetaData) const = 0;
};