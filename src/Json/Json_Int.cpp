#include "Json_Int.hpp"
#include <iostream>

using namespace std;

Json_Int::Json_Int(string key,int value){

    this->value = value;
    this->key = key;
}

void Json_Int::print(int depth_) {

    depth(depth_);
    string output = '"' + key + '"' + ": " + to_string(value);
    cout<<output;
}
