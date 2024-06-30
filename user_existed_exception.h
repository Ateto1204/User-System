#ifndef USER_EXISTED_EXCEPTION_H
#define USER_EXISTED_EXCEPTION_H

#include <string>
#include "my_exception.h"

class UserExistedException: public MyException {
public: 
    UserExistedException(): MyException("The User Has Existed") {}
    UserExistedException(std::string msg): MyException(msg) {}
};

#endif