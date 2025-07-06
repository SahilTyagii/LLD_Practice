#pragma once
#include "Common.hpp"
#include "Votable.hpp"
#include "User.hpp"

class Vote {
private:
    int id;
    Votable* votable;
    User* voter;
    int value;
public:
    Vote(Votable* votable, User* voter, int value): votable(votable), voter(voter), value(value) {}
    int getId() {
        return id;
    }
    int getValue() {
        return value;
    }
};