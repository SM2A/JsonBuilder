#include "Invalid_ID_Exception.hpp"

const char* Invalid_ID_Exception::what() const throw(){

    return "Invalid id.\n";
}