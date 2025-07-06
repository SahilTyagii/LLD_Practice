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
    TagManager* getTagManager();
    void addTag(string name, Tag* tag);
    unordered_map<string, Tag*> getTag();
    Tag* getTag(string name);
};