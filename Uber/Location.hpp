#pragma once

class Location {
public:
    const double latitude;
    const double longitude;
    Location(double lattitude, double longitude): latitude(latitude), longitude(longitude) {}
};