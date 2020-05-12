#include "Json_Array.hpp"

using namespace std;

Json_Array::Json_Array(string key, int id) : Json_Container::Json_Container(id) {
    Json_Container::key=key;
    this->start='[';
    this->stop=']';
}

Json_Array::Json_Array(int id) : Json_Container(id) {
    this->start='[';
    this->stop=']';
}
