#include "Json_String.hpp"
#include <iostream>

using namespace std;

Json_String::Json_String(string key, string value){

    this->value=value;
    this->key=key;
}

void Json_String::print(int depth_) {

    depth(depth_);
    string output = '"' + key + '"' + ": " + '"' + value + '"';
    cout<<output;
}