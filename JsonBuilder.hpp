#ifndef __JSON_BUILDER_H__
#define __JSON_BUILDER_H__

#include <string>
#include <map>
#include "Json_Object.hpp"
#include "Json_Container.hpp"

typedef std::map<int,Json_Container*> container_data;
typedef std::pair<int,Json_Container*> id_container;

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
    container_data containers;
    Json_Container* find_parent(int id);
    int generate_id();

};

#endif