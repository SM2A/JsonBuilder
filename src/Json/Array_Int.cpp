#include "Array_Int.hpp"
#include <iostream>

using  namespace std;

Array_Int::Array_Int(int value) {

    this->value = value;
}

void Array_Int::print(int depth_) {

    depth(depth_);
    cout<<value;
}
