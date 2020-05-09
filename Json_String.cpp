#include "Json_String.hpp"
#include <iostream>

using namespace std;

Json_String::Json_String(string key, string value) : Json_Data::Json_Data(key){

    this->value=value;
}

void Json_String::print() {

    string output = '"' + key + '"' + ": " + '"' + value + '"';
    cout<<output;
}