#include <iostream>

#include "user_repository.h"
#include "user.h"

#include "my_exception.h"
#include "user_not_found_exception.h"
#include "pwd_incorrect_exception.h"
#include "user_existed_exception.h"


User* UserRepository::getUserByEmail(std::string email, std::string pwd) {
    User *user = users[email];
    if (user == nullptr) {
        throw UserNotFoundException();
    }
    if (user->getPwd() != pwd) {
        throw PwdIncorrectException();
    }
    return user;
}

void UserRepository::saveUser(User *user) {
    std::string email = user->getEmail();
    if (users[email] != nullptr) {
        throw UserExistedException();
    }
    users[email] = user;
}