#include "JsonBuilder.hpp"
#include "Json_String.hpp"
#include "Json_Array.hpp"
#include "Json_Int.hpp"
#include "Array_Int.hpp"
#include "Array_String.hpp"

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

    Json_Container *container = find_parent(parentId);
    Json_String *j_string = new Json_String(key, value);
    container->add_element(j_string);
}

void JsonBuilder::addIntegerToObject(int parentId, string key, int value) {

    Json_Container *container = find_parent(parentId);
    Json_Int *j_int = new Json_Int(key, value);
    container->add_element(j_int);
}

int JsonBuilder::addContainerToObject(int parentId, string key, string type) {

    Json_Container *container = find_parent(parentId);
    Json_Container *j_container;
    int new_id = generate_id();

    if (type == OBJECT) j_container = new Json_Object(key, new_id);
    else if (type == ARRAY) j_container = new Json_Array(key, new_id);

    container->add_element(j_container);
    containers.insert(id_container(new_id, j_container));
    return new_id;
}

void JsonBuilder::addStringToArray(int parentId, string value) {

    Json_Container *container = find_parent(parentId);
    Array_String *a_string = new Array_String(value);
    container->add_element(a_string);
}

void JsonBuilder::addIntegerToArray(int parentId, int value) {

    Json_Container *container = find_parent(parentId);
    Array_Int *a_int = new Array_Int(value);
    container->add_element(a_int);
}

int JsonBuilder::addContainerToArray(int parentId, string type) {

    Json_Container *container = find_parent(parentId);
    Json_Container *a_container;
    int new_id = generate_id();

    if (type == OBJECT) a_container = new Json_Object(new_id);
    else if (type == ARRAY) a_container = new Json_Array(new_id);

    container->add_element(a_container);
    containers.insert(id_container(new_id, a_container));
    return new_id;
}

void JsonBuilder::print(int id) {

    Json_Container *container = find_parent(id);
    container->print(MASTER_OBJECT);
}

Json_Container *JsonBuilder::find_parent(int id) {

    for (id_container i : containers)
        if (i.first == id) return i.second;

    return nullptr;
}

int JsonBuilder::generate_id() {
    return (containers.end()->first) + NEXT_ID;
}