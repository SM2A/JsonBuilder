#ifndef JSON_INT_HPP
#define JSON_INT_HPP

#include <string>
#include "Json_Data.hpp"

class Json_Int : public Json_Data{

private:

    int value;
    std::string key;

public:

    Json_Int(std::string key,int value);
    void print();

};

#endif