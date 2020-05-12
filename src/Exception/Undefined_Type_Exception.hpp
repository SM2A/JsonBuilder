#ifndef UNDEFINED_TYPE_EXCEPTION_HPP
#define UNDEFINED_TYPE_EXCEPTION_HPP

#include <exception>

class Undefined_Type_Exception : public std::exception {

public:

    const char* what() const throw();

};

#endif