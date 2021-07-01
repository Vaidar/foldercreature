#include "../include/grass.h"
#include "../include/ecosystem.h"

Grass::Grass(std::string name, std::string path) : Life(name, LifeFormType::Grass, path) {
    this->self << this->name << std::endl;
    this->self << this->currentDir << std::endl;
}

int Grass::doAction() {
    if (checkIfDead()) {
        return -1;
    }

    this->reproduce();

    return 0;
}

void Grass::reproduce() {
    Grass* newGrass = new Grass("test", this->currentDir);
    
    // Detta funkar men måste kalla på Ecosystem.addToList(). Hur gör ja det?
    // Äre ok att includea ecosystem.h bara för detta?
    // Nä bara returnera något instället.

    // Hur ska detta gå till? Det ska inte bara skapas en ny fil utan det ska
    // skapas en ny instans av Grass klassen.

    // Kanske göra så att doAction() returnerar något när det ska bli en till.
}