#include "../include/grass.h"
#include "../include/ecosystem.h"

Grass::Grass(std::string name, std::string path, int birthTime) : Life(name, LifeFormType::Grass, path, birthTime) {
    this->self << this->name << std::endl;
    this->self << this->currentDir << std::endl;
}

int Grass::doSpecificActions() {
    if (checkIfDead()) {
        return -1;
    }

    getNearbyFilesAndFolders();
    if (this->nearbyFiles.size() < 20) {
        if (this->reproduce()) {
            return 1;
        }
    }

    return 0;
}

bool Grass::reproduce() {
    //Grass* newGrass = new Grass(std::to_string(rand()), this->currentDir);

    return true;
    
    // Detta funkar men måste kalla på Ecosystem.addToList(). Hur gör ja det?
    // Äre ok att includea ecosystem.h bara för detta?
    // Nä bara returnera något instället.

    // Hur ska detta gå till? Det ska inte bara skapas en ny fil utan det ska
    // skapas en ny instans av Grass klassen.

    // Kanske göra så att doSpecificActions() returnerar något när det ska bli en till.
}