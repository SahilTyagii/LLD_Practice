#pragma once

#include "PricingStrategy.hpp"
#include "Common.hpp"
using namespace std;

class RatingBasedPricingStrategy: public PricingStrategy {
public:
    double calculatePrice(TripMetaData* tripMetaData) const override {
        const double price = Util::isHighRating(tripMetaData->getRiderRating()) ? 80.0 : 90.0;
        cout << "Based on " << Util::ratingToString(tripMetaData->getRiderRating()) << " rider rating, price of trip is $" << price << endl;
        return price;
    }
};