#include "MyException.h"
#include <iostream>;

MyException::MyException(std::string error) {
    bad_figure_ = error;
}

const char* MyException::what() {
    std::cout << "�� ��� ������. ";
    return bad_figure_.c_str();
}
