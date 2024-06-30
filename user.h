#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string name;
    std::string email;
    std::string pwd;

public:
    User(std::string name, std::string email, std::string pwd);
    std::string getName();
    std::string getEmail();
    std::string getPwd();
};

#endif