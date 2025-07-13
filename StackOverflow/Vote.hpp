#pragma once
#include "Common.hpp"
#include "Votable.hpp"
#include "User.hpp"

class Vote {
private:
    int id;
    static int nextId;
    Votable* votable;
    User* voter;
    int value;
public:
    Vote(Votable* votable, User* voter, int value): id(nextId++), votable(votable), voter(voter), value(value) {
        votable->addVote(this);
        votable->getVoter()->addReputation(value);
    }
    int getId() {
        return id;
    }
    int getValue() {
        return value;
    }
};