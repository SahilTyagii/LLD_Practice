#pragma once

#include "Driver.hpp"
#include "Rider.hpp"

using namespace std;

class TripMetaData {
private:
    Rating riderRating;
    Rating driverRating;
    const Location* srcLoc;
    const Location* destLoc;
public:
    TripMetaData(Rating riderRating, Location* srcLoc, Location* destLoc): riderRating(riderRating), srcLoc(srcLoc), destLoc(destLoc) {}

    void setDriverRating(Rating driverRating) {
        this->driverRating = driverRating;
    }

    Rating getRiderRating() {return riderRating;}

    Rating getDriverRating() {return driverRating;}
};