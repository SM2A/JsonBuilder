#include "JsonBuilder.hpp"
#include "Json_String.hpp"
#include "Json_Array.hpp"
#include "Json_Int.hpp"
#include "Array_Int.hpp"
#include "Array_String.hpp"
#include "Duplicate_Key_Exception.hpp"
#include "Invalid_ID_Exception.hpp"
#include "Undefined_Type_Exception.hpp"
#include <iostream>

#define MASTER 0
#define MASTER_KEY ""
#define NEXT_ID 1
#define ARRAY "array"
#define OBJECT "object"
#define MASTER_OBJECT -1

using namespace std;

JsonBuilder::JsonBuilder() {

    master = new Json_Object(MASTER_KEY, MASTER);
    containers.insert(id_container(MASTER, master));
}

void JsonBuilder::addStringToObject(int parentId, string key, string value) {

    try {
        Json_Container *container = find_parent(parentId);
        Json_String *j_string = new Json_String(key, value);
        if(container== nullptr) throw Invalid_ID_Exception();
        container->add_element(j_string);
    }catch (Invalid_ID_Exception& exception){
        cerr<<exception.what()<<endl;
        abort();
    }
}

void JsonBuilder::addIntegerToObject(int parentId, string key, int value) {

    try {
        Json_Container *container = find_parent(parentId);
        Json_Int *j_int = new Json_Int(key, value);
        if(container== nullptr) throw Invalid_ID_Exception();
        container->add_element(j_int);
    }catch (Invalid_ID_Exception& exception){
        cerr<<exception.what()<<endl;
        abort();
    }
}

int JsonBuilder::addContainerToObject(int parentId, string key, string type) {

    try {
        Json_Container *container = find_parent(parentId);
        if (container == nullptr) throw Invalid_ID_Exception();
        Json_Container *j_container;
        int new_id = generate_id();

        if (type == OBJECT) j_container = new Json_Object(key, new_id);
        else if (type == ARRAY) j_container = new Json_Array(key, new_id);
        else throw Undefined_Type_Exception();

        container->add_element(j_container);
        containers.insert(id_container(new_id, j_container));
        return new_id;
    }catch (Invalid_ID_Exception& exception){
        cerr<<exception.what()<<endl;
        abort();
    }catch (Undefined_Type_Exception& exception){
        cerr<<exception.what()<<endl;
        abort();
    }
}

void JsonBuilder::addStringToArray(int parentId, string value) {

    try {
        Json_Container *container = find_parent(parentId);
        Array_String *a_string = new Array_String(value);
        if (container == nullptr) throw Invalid_ID_Exception();
        container->add_element(a_string);
    }catch (Invalid_ID_Exception& exception){
        cerr<<exception.what()<<endl;
        abort();
    }
}

void JsonBuilder::addIntegerToArray(int parentId, int value) {

    try {
        Json_Container *container = find_parent(parentId);
        Array_Int *a_int = new Array_Int(value);
        if (container == nullptr) throw Invalid_ID_Exception();
        container->add_element(a_int);
    }catch (Invalid_ID_Exception& exception){
        cerr<<exception.what()<<endl;
        abort();
    }
}

int JsonBuilder::addContainerToArray(int parentId, string type) {

    try {
        Json_Container *container = find_parent(parentId);
        if (container == nullptr) throw Invalid_ID_Exception();
        Json_Container *a_container;
        int new_id = generate_id();

        if (type == OBJECT) a_container = new Json_Object(new_id);
        else if (type == ARRAY) a_container = new Json_Array(new_id);
        else throw Undefined_Type_Exception();

        container->add_element(a_container);
        containers.insert(id_container(new_id, a_container));
        return new_id;
    }catch (Invalid_ID_Exception& exception){
        cerr<<exception.what()<<endl;
        abort();
    }catch (Undefined_Type_Exception& exception){
        cerr<<exception.what()<<endl;
        abort();
    }
}

void JsonBuilder::print(int id) {

    try {
        Json_Container *container = find_parent(id);
        if(container== nullptr) throw Invalid_ID_Exception();
        container->print(MASTER_OBJECT);
        cout << endl;
    }catch (Invalid_ID_Exception& exception){
        cerr<<exception.what()<<endl;
        abort();
    }
}

Json_Container *JsonBuilder::find_parent(int id) {

    for (id_container i : containers)
        if (i.first == id) return i.second;

    return nullptr;
}

int JsonBuilder::generate_id() {
    return (containers.end()->first) + NEXT_ID;
}