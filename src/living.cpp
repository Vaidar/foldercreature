/*
 * This the file that will run the ecosystem
*/

#include <unistd.h>
#include "../include/ecosystem.h"
#include "../include/grasseater.h"
#include "../include/grass.h"

// TODO: Fundera på hur strukturen ska se ut när det ska vara många varelser och växter.
int main(void) {
    std::string name = "oogabooga";
    std::string path = "./Cage/1";
    
    Ecosystem* ecosystem = new Ecosystem(path);

    GrassEater* c = new GrassEater(name, path);
    Grass* g = new Grass("igelbigel", path);

    ecosystem->addLifeFormToList(c);
    ecosystem->addLifeFormToList(g);

    for (int i = 0; i < 100; i++) {
        ecosystem->tick();
    }

    std::cout << c->getName() << " is in: " << c->getPath() << std::endl;

    //c.kill();
    return 0;
}