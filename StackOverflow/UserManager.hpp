#include "User.hpp"
#include <mutex>

class UserManager {
private:
    static UserManager* userManagerInstance;
    unordered_map<int, User*> userMap;
    static mutex mtx;
    UserManager() {}
public:
    static UserManager* getUserManager();
    void addUser(User* user);
    unordered_map<int, User*> getUserMap();
};