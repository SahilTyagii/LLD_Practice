#pragma once
#include "User.hpp"
#include "Common.hpp"

using namespace std;

class Rider: public User {
public:
    Rider(string name, Rating rating): User(name, rating) {}
    string getUserType() const override {
        return "Rider";
    }
};