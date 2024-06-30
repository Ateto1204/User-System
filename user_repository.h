#ifndef USER_REPOSITORY_H
#define USER_REPOSITORY_H

#include <string>
#include <unordered_map>
#include "user.h"

class UserRepository {
private: 
    std::unordered_map<std::string, User*> users;
public: 
    User* getUserByEmail(std::string email, std::string pwd);
    void saveUser(User *user);
};

#endif