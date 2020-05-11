#include "Undefined_Type_Exception.hpp"

const char* Undefined_Type_Exception::what() const throw(){

    return "Undefined type.";
}