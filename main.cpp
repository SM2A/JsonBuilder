#include "JsonBuilder.hpp"

using namespace std;

int main() {

    JsonBuilder jsonBuilder;

    jsonBuilder.addStringToObject(0, "color", "red");
    jsonBuilder.addIntegerToObject(0, "diameter", 25);
    int coursesId = jsonBuilder.addContainerToObject(0, "courses", "array");
    jsonBuilder.addStringToArray(coursesId, "AP");
    jsonBuilder.addStringToArray(coursesId, "DM");
    jsonBuilder.addIntegerToArray(coursesId, 5);
    int gradesId = jsonBuilder.addContainerToObject(0, "grades", "array");
    jsonBuilder.addIntegerToArray(gradesId, 20);
    int infoId = jsonBuilder.addContainerToObject(0, "info", "object");
    jsonBuilder.addStringToObject(infoId, "name", "hosna");
    jsonBuilder.addStringToObject(infoId, "email", "hsazarmsa@gmail.com");
    jsonBuilder.print(0);

    JsonBuilder jsonBuilder1;
    jsonBuilder1.addStringToObject(0,"name","amin");
    int x = jsonBuilder1.addContainerToObject(0,"courses","object");
    int y = jsonBuilder1.addContainerToObject(x,"ap","object");
    int z = jsonBuilder1.addContainerToObject(y,"grades","array");
    jsonBuilder1.addIntegerToArray(z,12);
    jsonBuilder1.addIntegerToArray(z,23);
    jsonBuilder1.addIntegerToArray(z,85);
    jsonBuilder1.print(0);
}