#include "Json_Object.hpp"

using namespace std;

Json_Object::Json_Object(string key, int id) : Json_Container::Json_Container(id) {
    Json_Container::key=key;
    this->start='{';
    this->stop='}';
}

Json_Object::Json_Object(int id) : Json_Container(id) {
    this->start='{';
    this->stop='}';
}
