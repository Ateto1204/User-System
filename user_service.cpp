#include "user_service.h"
#include "user.h"

#include "my_exception.h"
#include "user_not_found_exception.h"
#include "pwd_incorrect_exception.h"

UserService::UserService(UserRepository* repo): repository(repo) {}

User* UserService::getUserByEmail(std::string email, std::string pwd) {
    try {
        User *user = repository->getUserByEmail(email, pwd);
        return user;
    } catch (const UserNotFoundException& exception) {
        exception.showMsg();
        throw exception;
    } catch (const PwdIncorrectException& exception) {
        exception.showMsg();
        throw exception;
    } catch (const MyException& exception) {
        exception.showMsg();
        throw exception;
    }
    return NULL;
}

void UserService::saveUser(User *user) {
    try {
        repository->saveUser(user);
    } catch (const MyException& exception) {
        exception.showMsg();
    }
}

void UserService::saveUser(std::string name, std::string email, std::string pwd) {
    User *user = new User(name, email, pwd);
    repository->saveUser(user);
}