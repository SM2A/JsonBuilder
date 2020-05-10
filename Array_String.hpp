#ifndef A6_ARRAY_STRING_HPP
#define A6_ARRAY_STRING_HPP

#include <string>
#include "Json_Data.hpp"

class Array_String : public Json_Data {

public:

    Array_String(std::string value);
    void print(int depth_=0);

private:

    std::string value;

};

#endif