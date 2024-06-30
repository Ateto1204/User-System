#ifndef MY_EXCEPTION_H
#define MY_EXCEPTION_H

#include <iostream>
#include <string>

class MyException {
private: 
    std::string errMsg;
public: 
    MyException(): errMsg("Unknown Exception") {}
    MyException(std::string msg): errMsg(msg) {}
    void showMsg() const {
        std::cerr << errMsg << std::endl;
    }
};

#endif