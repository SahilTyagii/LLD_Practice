#pragma once

#include "Common.hpp"
#include "Taggable.hpp"

class Tag {
private:
    int id;
    static int nextId;
    string name;
    vector<Taggable*> taggables;
public:
    Tag(string name): id(nextId++), name(name) {}
    int getId() {
        return id;
    }
    void addQuestion(Taggable* taggable) {
        taggables.push_back(taggable);
        taggable->addTag(this);
    }
    string getName() {
        return name;
    }
};