#include "Json_Container.hpp"

using namespace std;

Json_Container::Json_Container(int id){

    this->id=id;
}

void Json_Container::add_element(Json_Data *json_data) {

    content.push_back(json_data);
}