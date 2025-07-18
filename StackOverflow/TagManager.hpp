#pragma once

#include "Common.hpp"
#include "Tag.hpp"
#include <mutex>

class TagManager {
private:
    static TagManager* tagManagerInstance;
    unordered_map<string, Tag*> tagsMap;
    static mutex mtx;
    TagManager() {}
public:
    static TagManager* getTagManager();
    void addTag(string name, Tag* tag);
    unordered_map<string, Tag*> getTagMap();
    Tag* getTag(string name);
};