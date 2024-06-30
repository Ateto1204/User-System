#include "user.h"

User::User(std::string name, std::string email, std::string pwd)
    : name(name), email(email), pwd(pwd) {}

std::string User::getName() {
    return name;
}

std::string User::getEmail() {
    return email;
}

std::string User::getPwd() {
    return pwd;
}