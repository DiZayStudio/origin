#include "MyException.h"
#include <iostream>;

MyException::MyException(std::string error) {
    bad_figure_ = error;
}

const char* MyException::what() {
    std::cout << "не был создан. ";
    return bad_figure_.c_str();
}
