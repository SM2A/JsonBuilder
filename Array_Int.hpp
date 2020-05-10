#ifndef A6_ARRAY_INT_HPP
#define A6_ARRAY_INT_HPP

#include "Json_Data.hpp"

class Array_Int : public  Json_Data{

public:

    Array_Int(int value);
    void print(int depth_=0);

private:

    int value;

};

#endif