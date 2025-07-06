#pragma once

#include "TripMetaData.hpp"
#include "DriverManager.hpp"

using namespace std;

class MatchingStrategy {
public:
    virtual Driver* matchDriver(TripMetaData* tripMetaData) const = 0;
};