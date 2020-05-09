#ifndef JSON_DATA_HPP
#define JSON_DATA_HPP

#include <string>

class Json_Data {

public:

    Json_Data(std::string key);
    virtual void print() = 0;

protected:

    std::string key;

};

#endif