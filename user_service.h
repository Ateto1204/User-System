#ifndef USER_SERVICE_H
#define USER_SERVICE_H

#include "user_repository.h"

class UserService {
private: 
    UserRepository *repository;

public: 
    UserService(UserRepository *repo);
    User* getUserByEmail(std::string email, std::string pwd);
    void saveUser(User *user);
    void saveUser(std::string name, std::string email, std::string pwd);
};

#endif 