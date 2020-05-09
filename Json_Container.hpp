#ifndef JSON_CONTAINER_HPP
#define JSON_CONTAINER_HPP

#include "Json_Data.hpp"

class Json_Container :public Json_Data{

public:

    Json_Container(std::string key,int id);
    virtual void print()=0;

private:

    int id;

};


#endif