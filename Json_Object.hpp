#ifndef JSON_OBJECT_HPP
#define JSON_OBJECT_HPP

#include <vector>
#include "Json_Container.hpp"

typedef std::vector<Json_Data> data;

class Json_Object : public Json_Container{

public:

    Json_Object(std::string key,int id);
    void print();

private:

    data content;

};

#endif