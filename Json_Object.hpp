#ifndef JSON_OBJECT_HPP
#define JSON_OBJECT_HPP

#include "Json_Container.hpp"

class Json_Object : public Json_Container{

public:

    Json_Object(std::string key,int id);
    Json_Object(int id);

};

#endif