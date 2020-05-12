#ifndef __JSON_BUILDER_H__
#define __JSON_BUILDER_H__

#include <string>
#include <map>
#include "Json_Object.hpp"
#include "Json_Container.hpp"

typedef std::map<int,Json_Container*> container_data;
typedef std::pair<int,Json_Container*> id_container;
typedef std::pair<int,std::string> id_key;
typedef std::vector<id_key> key_data;

class JsonBuilder{

public:

    JsonBuilder();
    void addStringToObject(int parentId, std::string key, std::string value);
    void addIntegerToObject(int parentId, std::string key, int value);
    int addContainerToObject(int parentId, std::string key, std::string type);
    void addStringToArray(int parentId, std::string value);
    void addIntegerToArray(int parentId, int value);
    int addContainerToArray(int parentId, std::string type);
    void print(int id);

private:

    Json_Object* master;
    container_data object_containers;
    container_data array_containers;
    key_data keys;
    Json_Container* find_parent_object(int id);
    Json_Container* find_parent_array(int id);
    void available_key(int id , std::string key);
    int generate_id();

};

#endif
