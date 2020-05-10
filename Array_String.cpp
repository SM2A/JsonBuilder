#include "Array_String.hpp"
#include <iostream>

using namespace std;

Array_String::Array_String(std::string value) {

    this->value = value;
}

void Array_String::print(int depth_) {

    depth(depth_);
    string output = '"' + value + '"';
    cout<<output;
}
