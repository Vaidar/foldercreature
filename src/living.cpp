/*
 * This the file that will run the ecosystem
*/

#include "../include/ecosystem.h"
#include "../include/creature.h"
#include "../include/grass.h"

// TODO: Fundera på hur strukturen ska se ut när det ska vara många varelser och växter.
int main(void) {
    std::string name = "oogabooga";
    std::string path = "./Cage/1";
    
    EcoSystem* ecoSystem = new EcoSystem(path);
    Creature c(name, path);
    Grass g("igelbigel", path);

    for (int i = 0; i < 100; i++) {
        ecoSystem->tick();
        c.move();
    }

    std::cout << c.getName() << " is in: " << c.getPath() << std::endl;

    //c.kill();
    return 0;
}