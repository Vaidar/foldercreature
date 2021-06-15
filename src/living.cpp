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

    Creature* c = new Creature(name, path);
    Grass* g = new Grass("igelbigel", path);

    ecoSystem->addLifeFormToList(c);

    for (int i = 0; i < 100; i++) {
        ecoSystem->tick();
    }

    std::cout << c->getName() << " is in: " << c->getPath() << std::endl;

    //c.kill();
    return 0;
}