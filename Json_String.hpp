#ifndef JSON_STRING_HPP
#define JSON_STRING_HPP

#include "Json_Data.hpp"
#include <string>

class Json_String : public Json_Data{

public:

    Json_String(std::string key , std::string value);
    void print();

private:

    std::string value;
    std::string key;

};

#endif