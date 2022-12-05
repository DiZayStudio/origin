#pragma once

#include <exception>
#include <string>


class MyException  : public std::exception {
private:
   std::string bad_figure_;
public:
	MyException(std::string bad_figure);

   virtual const char* what();
};
