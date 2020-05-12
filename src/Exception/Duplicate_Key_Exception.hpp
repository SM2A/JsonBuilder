#ifndef A6_DUPLICATE_KEY_EXCEPTION_HPP
#define A6_DUPLICATE_KEY_EXCEPTION_HPP

#include <exception>

class Duplicate_Key_Exception : public std::exception{

public:

    const char* what() const throw();
};

#endif