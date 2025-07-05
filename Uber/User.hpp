#pragma once
#include "Common.hpp"

using namespace std;

class User {
private:
    string id;
    string name;
    Rating rating;
public:
    User(string name, Rating rating): name(name), rating(rating) {}
    string getName() {
        return name;
    }
    Rating getRating() {
        return rating;
    }
    virtual string getUserType() const = 0;
    virtual ~User() = default;
};