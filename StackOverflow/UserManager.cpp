#include "UserManager.hpp"

UserManager* UserManager::userManagerInstance = nullptr;
mutex UserManager::mtx;

UserManager* UserManager::getUserManager() {
    if (userManagerInstance == nullptr) {
        mtx.lock();
        if (userManagerInstance == nullptr) {
            userManagerInstance = new UserManager();
        }
        mtx.unlock();
    }
    return userManagerInstance;
}

void UserManager::addUser(User* user) {
    userMap[user->getId()] = user;
}

unordered_map<int, User*> UserManager::getUserMap() {
    return userMap;
}