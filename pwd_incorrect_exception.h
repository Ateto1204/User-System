#ifndef PWD_INCORRECT_EXCEPTION_H
#define PWD_INCORRECT_EXCEPTION_H

#include <string>
#include "my_exception.h"

class PwdIncorrectException: public MyException {
public: 
    PwdIncorrectException(): MyException("The Password Incorrect") {}
    PwdIncorrectException(std::string msg): MyException(msg) {}
};

#endif 