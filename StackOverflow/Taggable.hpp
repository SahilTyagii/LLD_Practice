#pragma once

#include "Common.hpp"
#include "Tag.hpp"

class Taggable {
protected:
    unordered_map<int, Tag*> tagsMap;
public:
    virtual unordered_map<int, Tag*> getTagsMap() const = 0;
    virtual void addTag(Tag* tag) = 0;
};