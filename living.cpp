/*
 * This the folder that will run the creature
*/

#include "creature.h"

int main(void) {
    std::string name = "oogabooga";
    std::string path = "./Cage/1";
    Creature c(name, path);
    c.move("..");
    //c.kill();
    return 0;
}