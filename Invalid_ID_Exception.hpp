#ifndef INVALID_ID_EXCEPTION_HPP
#define INVALID_ID_EXCEPTION_HPP

#include <exception>

class Invalid_ID_Exception : public std::exception{

public:

    const char* what() const throw();
};

#endif