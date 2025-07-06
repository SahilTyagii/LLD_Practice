#pragma once
#include "Common.hpp"
#include "User.hpp"

using namespace std;

class Driver: public User {
private:
    bool isAvailable;
public:
    Driver(string name, Rating rating): User(name, rating) {
        isAvailable = false;
    }
    string getUserType() const override {
        return "Driver";
    }
    void setAvailable(bool isAvailable) {
        this->isAvailable = isAvailable;
    }
};