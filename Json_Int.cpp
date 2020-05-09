#include "Json_Int.hpp"
#include <iostream>

using namespace std;

Json_Int::Json_Int(string key,int value) : Json_Data::Json_Data(key) {

    this->value = value;
}

void Json_Int::print() {

    string output = '"' + key + '"' + ": " + to_string(value);
    cout<<output;
}
