/*
 * This the folder that will run the creature
*/

#include "creature.h"

int main(void) {
    std::string name = "oogabooga";
    std::string path = "C:\\Users\\vidar\\Documents\\Hackerfolder\\Cpp-things\\folderorganism";
    Creature c(name, path);
    c.move("..");
    return 0;
}