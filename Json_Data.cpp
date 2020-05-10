#include "Json_Data.hpp"
#include <iostream>

using namespace std;

Json_Data::Json_Data() {}

void Json_Data::depth(int depth_) {

    for(int i = 0 ; i < depth_ ; i++) cout<<"    ";
}