#pragma once
#include <iostream>
#include <unordered_map>
#include "Location.hpp"

using namespace std;

static int nextTripId = 1;

enum class Rating {
    UNASSIGNED,
    ONE_STAR,
    TWO_STAR,
    THREE_STAR,
    FOUR_STAR,
    FIVE_STAR
};

enum class TRIP_STATUS {
    UNASSIGNED,
    DRIVER_ON_THE_WAY,
    DRIVER_ARRIVED,
    STARTED,
    PAUSED,
    CANCELLED,
    ENDED
};

class Util {
public:
    static string ratingToString(Rating rating) {
        switch (rating)
        {
        case Rating::ONE_STAR:
            return "one star";
        case Rating::TWO_STAR:
            return "two star";
        case Rating::THREE_STAR:
            return "three star";
        case Rating::FOUR_STAR:
            return "four star";
        case Rating::FIVE_STAR:
            return "five star";
        }
        return "invalid rating";
    }
    static bool isHighRating(Rating rating) {
        return rating == Rating::FIVE_STAR || rating == Rating::FOUR_STAR;
    }
};