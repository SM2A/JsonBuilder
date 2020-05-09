#ifndef JSON_ARRAY_HPP
#define JSON_ARRAY_HPP

#include "Json_Container.hpp"

class Json_Array : public Json_Container{

public:

    Json_Array(std::string key,int id);
    void print();

};

#endif