/*
 * This the file that will run the creature
*/

#include "creature.h"

// TODO: Fundera på hur strukturen ska se ut när det ska vara många varelser och växter.
int main(void) {
    std::string name = "oogabooga";
    std::string path = "./Cage/1";
    
    Creature c(name, path);

    for (int i = 0; i < 100; i++) {
        c.move();
    }

    //c.kill();
    return 0;
}