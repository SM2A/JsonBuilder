#include "../../JsonBuilder.hpp"
#include "Json_String.hpp"
#include "Json_Array.hpp"
#include "Json_Int.hpp"
#include "Array_Int.hpp"
#include "Array_String.hpp"
#include "../Exception/Duplicate_Key_Exception.hpp"
#include "../Exception/Invalid_ID_Exception.hpp"
#include "../Exception/Undefined_Type_Exception.hpp"
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
    object_containers.insert(id_container(MASTER, master));
    keys.push_back(id_key(MASTER,MASTER_KEY));
}

void JsonBuilder::addStringToObject(int parentId, string key, string value) {

    Json_Container *container = find_parent_object(parentId);
    available_key(parentId, key);
    Json_String *j_string = new Json_String(key, value);
    container->add_element(j_string);
}

void JsonBuilder::addIntegerToObject(int parentId, string key, int value) {

    Json_Container *container = find_parent_object(parentId);
    available_key(parentId, key);
    Json_Int *j_int = new Json_Int(key, value);
    container->add_element(j_int);
}

int JsonBuilder::addContainerToObject(int parentId, string key, string type) {

    Json_Container *container = find_parent_object(parentId);
    available_key(parentId, key);
    Json_Container *j_container;
    int new_id = generate_id();

    if (type == OBJECT) {
        j_container = new Json_Object(key, new_id);
        object_containers.insert(id_container(new_id, j_container));
    } else if (type == ARRAY) {
        j_container = new Json_Array(key, new_id);
        array_containers.insert(id_container(new_id, j_container));
    } else throw Undefined_Type_Exception();

    container->add_element(j_container);
    return new_id;
}

void JsonBuilder::addStringToArray(int parentId, string value) {

    Json_Container *container = find_parent_array(parentId);
    Array_String *a_string = new Array_String(value);
    container->add_element(a_string);
}

void JsonBuilder::addIntegerToArray(int parentId, int value) {

    Json_Container *container = find_parent_array(parentId);
    Array_Int *a_int = new Array_Int(value);
    container->add_element(a_int);
}

int JsonBuilder::addContainerToArray(int parentId, string type) {

    Json_Container *container = find_parent_array(parentId);
    Json_Container *a_container;
    int new_id = generate_id();

    if (type == OBJECT) {
        a_container = new Json_Object(new_id);
        object_containers.insert(id_container(new_id, a_container));
    } else if (type == ARRAY) {
        a_container = new Json_Array(new_id);
        array_containers.insert(id_container(new_id, a_container));
    } else throw Undefined_Type_Exception();

    container->add_element(a_container);
    return new_id;
}

void JsonBuilder::print(int id) {

    Json_Container *container = find_parent_object(id);
    container->print(MASTER_OBJECT);
    cout << endl;
}

Json_Container *JsonBuilder::find_parent_object(int id) {

    for (id_container i : object_containers)
        if (i.first == id) return i.second;

    throw Invalid_ID_Exception();
}

Json_Container *JsonBuilder::find_parent_array(int id) {

    for (id_container i : array_containers)
        if (i.first == id) return i.second;

    throw Invalid_ID_Exception();
}

int JsonBuilder::generate_id() {

    return (object_containers.size() + array_containers.size()) + NEXT_ID;
}

void JsonBuilder::available_key(int id, string key) {

    for (id_key index : keys)
        if ((index.first == id) && (index.second == key)) throw Duplicate_Key_Exception();

    keys.push_back(id_key(id,key));
}
