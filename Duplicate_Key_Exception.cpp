#include "Duplicate_Key_Exception.hpp"

const char* Duplicate_Key_Exception::what() const throw(){

    return "Duplicate key.";
}
