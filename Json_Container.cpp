#include <iostream>
#include "Json_Container.hpp"

#define MASTER_OBJECT -1
#define EMPTY 0

using namespace std;

Json_Container::Json_Container(int id) {

    this->id = id;
}

void Json_Container::add_element(Json_Data *json_data) {

    content.push_back(json_data);
}

void Json_Container::print(int depth_) {

    depth(depth_);
    if ((depth_ != MASTER_OBJECT) && (this->key.size() != EMPTY)) {
        string key_ = '"' + this->key + '"' + ": ";
        cout << key_;
    } else if(depth_ == MASTER_OBJECT) depth_ = 0;
    cout << start;
    if (content.size() != EMPTY) {
        cout << endl;
        for (int i = 0; i < content.size(); i++) {
            content[i]->print(depth_ + 1);
            if (i != content.size() - 1) cout << ",";
            cout << endl;
        }
        depth(depth_);
    }
    cout << stop;
}
