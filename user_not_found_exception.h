#ifndef USER_NOT_FOUND_EXCEPTION_H
#define USER_NOT_FOUND_EXCEPTION_H

#include <string>
#include "my_exception.h"

class UserNotFoundException: public MyException {
public: 
    UserNotFoundException(): MyException("The User Doesn't Exist") {}
    UserNotFoundException(std::string msg): MyException(msg) {}
};

#endif