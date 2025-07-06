#pragma once

#include "Common.hpp"
#include "Taggable.hpp"

class Tag {
private:
    int id;
    string name;
    vector<Taggable*> taggables;
public:
    Tag(string name): name(name) {}
    int getId() {
        return id;
    }
    void addQuestion(Taggable* taggable) {
        taggables.push_back(taggable);
    }
};