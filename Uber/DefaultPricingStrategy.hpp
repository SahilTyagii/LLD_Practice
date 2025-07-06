#pragma once

#include "PricingStrategy.hpp"
using namespace std;

class DefaultPricingStrategy: public PricingStrategy {
public:
    double calculatePrice(TripMetaData* tripMetaData) const override {
        cout << "Based on default algorithm price is: $100.0\n";
        return 100.0;
    }
};