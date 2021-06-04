/*
 * This the folder that will run the creature
*/

#include "creature.h"

int main(void) {
    std::string name = "oogabooga";
    std::string path = "F:\\Hackerfolder\\Cpp-things\\foldercreature\\Cage\\1";
    Creature c(name, path);
    c.move("..");
    return 0;
}