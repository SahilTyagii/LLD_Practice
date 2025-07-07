#include "TagManager.hpp"

TagManager* TagManager::tagManagerInstance = nullptr;
mutex TagManager::mtx;

TagManager* TagManager::getTagManager() {
    if (tagManagerInstance == nullptr) {
        mtx.lock();
        if (tagManagerInstance == nullptr) {
            tagManagerInstance = new TagManager();
        }
        mtx.unlock();
    }
    return tagManagerInstance;
}

unordered_map<string, Tag*> TagManager::getTagMap() {
    return tagsMap;
}

Tag* TagManager::getTag(string tagName) {
    return tagsMap[tagName];
}

void TagManager::addTag(string tagName, Tag* tag) {
    tagsMap[tagName] = tag;
}