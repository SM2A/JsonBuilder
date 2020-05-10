#ifndef JSON_DATA_HPP
#define JSON_DATA_HPP

#include <string>

class Json_Data {

public:

    Json_Data();
    virtual void print(int depth_=0)=0;

protected:

    void depth(int depth_);

};

#endif