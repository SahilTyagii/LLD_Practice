#pragma once

#include "Common.hpp"
#include "Vote.hpp"

class Votable {
protected:
    unordered_map<int, Vote*> voteMap;
public:
    virtual int getVoteCount() const = 0;
    virtual void addVote(Vote*) = 0;
    virtual User* getVoter() const = 0;
};