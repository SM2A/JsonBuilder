#include "Json_Container.hpp"

using namespace std;

Json_Container::Json_Container(string key,int id) :Json_Data::Json_Data(key) {

    this->id=id;
}
